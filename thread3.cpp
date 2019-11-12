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
	std::thread mT3;
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
		std::cout << "t1 started" << std::endl;
		while (count-- > 0) {
			std::cout << "t1 " << count << std::endl;
			if (count == 8) {
				{
					std::lock_guard<std::mutex> lg(cv_lock);
					ready = true;
					std::cout << "notifying t2 from t1" << std::endl;
				}
				cv.notify_one();
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
		}
		std::cout << "t1 exiting" << std::endl;
	}

	void runt2() {
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		std::cout << "t2 started" << std::endl;
		while (true) {
			{
				std::unique_lock<std::mutex> lck(cv_lock);
				std::cout << "t2 waiting" << std::endl;
				cv.wait(lck, [this]{return ready;});
				std::cout << "t2 " << count << std::endl;
				ready = false;
			}
		}
	}

	void runt3() {
		{
			std::cout << "t3 started" << std::endl;
			std::lock_guard<std::mutex> lg(cv_lock);
			ready = true;
			std::cout << "notifying t2 from t3" << std::endl;
		}
		cv.notify_one();
	}

	void run(void) {
		mT1 = std::thread(&TestThreads::runt1, this);
		mT2 = std::thread(&TestThreads::runt2, this);
		mT2.detach();
		// mT3 = std::thread(&TestThreads::runt3, this);
	}
};



int main() {
	TestThreads t;
	t.run();
}