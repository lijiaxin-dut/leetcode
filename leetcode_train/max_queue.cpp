#include<queue>

using namespace std;

//请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的时间复杂度都是O(1)。
//
//若队列为空，pop_front 和 max_value 需要返回 - 1
//

//使用deque保存数据
//data保存实际数据
//maxnumber是一个降序的队列，front表示当前最大值

//记录加入的数字属于第几个，用index标识
//当前pop的元素如果与maxnumber.front相同，就弹出

class MaxQueue {
	struct val {
		int n_th;
		int number;
		val(int n, int num) :n_th(n), number(num) {}
	};
	deque<val>data;
	deque<val>maxnumber;
	int cur_index = 0;
public:
	MaxQueue() {

	}

	int max_value() {
		if (data.empty())
			return -1;
		return maxnumber.front().number;

	}

	void push_back(int value) {
		while (!maxnumber.empty() && value >= maxnumber.back().number)
			maxnumber.pop_back();
		maxnumber.emplace_back(cur_index, value);
		data.emplace_back(cur_index, value);
		cur_index++;
	}

	int pop_front() {
		if (data.empty())
			return -1;
		if (maxnumber.front().n_th == data.front().n_th)
			maxnumber.pop_front();
		int rs = data.front().number;
		data.pop_front();
		return rs;
	}
};

/**
* Your MaxQueue object will be instantiated and called as such:
* MaxQueue* obj = new MaxQueue();
* int param_1 = obj->max_value();
* obj->push_back(value);
* int param_3 = obj->pop_front();
*/