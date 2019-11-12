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
	TestThreads() {count=10;ready=false;};
	~TestThreads() {
		if (mT1.joinable()) {
			mT1.join();
		}
		if (mT2.joinable()) {
			mT2.join();
		}
	}
	void runt1() {
		while (count-- > 0) {
			std::cout << "t1 " << count << std::endl;
			if (count == 4) {
				std::lock_guard<std::mutex> lg(cv_lock);
				ready = true;
				std::cout << "notifying t2" << std::endl;
				// std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
			cv.notify_one();

			{
				std::unique_lock<std::mutex> lck(cv_lock);
				std::cout << "waiting for not ready" << std::endl;
				cv.wait(lck, [this]{return !ready;});
				std::cout << "here" << std::endl;
			}
		} 
	}

	void runt2() {
		std::unique_lock<std::mutex> lck(cv_lock);
		cv.wait(lck, [this]{return ready;});
		std::cout << "t2 " << count << std::endl;
		{
			std::cout << "waiting for cv lock" << std::endl;
			std::lock_guard<std::mutex> lg(cv_lock);
			ready = false;
		}
		cv.notify_one();
	}

	void run(void) {
		mT1 = std::thread(&TestThreads::runt1, this);
		mT2 = std::thread(&TestThreads::runt2, this);
	}
};



int main() {
	TestThreads t;
	t.run();
}