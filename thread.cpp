#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <sstream>

class TestThreads
{
private:
	int count;
	std::thread mT1;
	std::thread mT2;
	std::condition_variable cv;
	std::mutex cv_lock;
	bool ready;

public:
	TestThreads() {count=100;ready=true;};
	~TestThreads() {
		if (mT1.joinable()) {
			mT1.join();
		}
		if (mT2.joinable()) {
			mT2.join();
		}
		std::cout << "destroyed" << std::endl;
	}
	void runt1() {
		while (count-- > 0) {
			std::cout << "t1 " << count << std::endl;
			if (count == 5) {
				std::unique_lock<std::mutex> lck(cv_lock);
				ready = true;
				std::cout << "notifying t2" << std::endl;
				cv.notify_one();
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}

			{
				std::unique_lock<std::mutex> lck(cv_lock);
				while (ready) cv.wait(lck);
			}
			// if (mT2.joinable()) {
			// 	std::cout << "joining t2" << count << std::endl;
			// 	mT2.join();
			// }

		} 
	}
	static void t1(TestThreads *t) {
		t->runt1();
	}
	void runt2() {
		std::unique_lock<std::mutex> lck(cv_lock);
		while (!ready) cv.wait(lck);
		std::cout << "t2 " << count << std::endl;
		ready = false;
		cv.notify_one();
	}
	static void t2(TestThreads *t) {
		t->runt2();
	}
	void run(void) {
		mT1 = std::thread(&this->t1, this);
		mT2 = std::thread(&this->t2, this);
	}

	void runt3() {
		while (1) {
			std::unique_lock<std::mutex> lck(cv_lock);
			if (ready) {
				count--;
				if (count == 0) {
					std::cout << "Looping endlessly" << std::endl;
					break;
				}
				std::cout << "Processing" << std::endl;
				// std::this_thread::sleep_for(std::chrono::milliseconds(1));
			} else {
				cv.wait(lck, [this]{return ready;});
				break;
			}
			lck.unlock();
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
		std::cout << "Exiting t3" << std::endl;
	}
	static void t3(TestThreads *t) {
		t->runt3();
	}
	void runt4() {
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		{
			std::lock_guard<std::mutex> lg(cv_lock);
			ready = false;
			std::cout << "notifying not ready" << std::endl;
			cv.notify_one();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		{
			std::lock_guard<std::mutex> lg(cv_lock);
			ready = true;
			std::cout << "notifying ready" << std::endl;
			cv.notify_one();
		}
		std::cout << "Exiting t4" << std::endl;
	}
	static void t4(TestThreads *t) {
		t->runt4();
	}
	void run2(void) {
		mT1 = std::thread(&this->t3, this);
		mT2 = std::thread(&this->t4, this);
	}
};



int main() {
	TestThreads t;
	t.run2();
}