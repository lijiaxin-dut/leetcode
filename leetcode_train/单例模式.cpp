#include<atomic>
#include<mutex>
using namespace std;

class Single {
public:

	static std::atomic<Single *> p_instance;
	static std::mutex m;

	Single* getInstance() {
		if (p_instance.load() == nullptr) {
			lock_guard<mutex> lock{ m };
			if (p_instance.load() == nullptr) {
				p_instance = new Single();
			}
		}
		return p_instance;
	}
};
std::atomic<Single *> Single::p_instance = nullptr;

