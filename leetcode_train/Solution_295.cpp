#include<queue>
#include<functional>
using namespace std;

//Median is the middle value in an ordered integer list.If the size of the list is even, there is no middle value.So the median is the mean of the two middle value.
//
//For example,
//[2, 3, 4], the median is 3
//
//[2, 3], the median is(2 + 3) / 2 = 2.5
//
//Design a data structure that supports the following two operations :
//
//void addNum(int num) - Add a integer number from the data stream to the data structure.
//double findMedian() - Return the median of all elements so far.


//用两个堆保存数据
//最大堆保存较小一半的数字
//最小堆保存较大一半的数字

//使用保持最大堆的size>=最小堆的size
//最大堆：1 2 3  最小堆：  4 5   这种情况返回最大堆堆顶
//否则返回两个堆顶求和/2

//插入时，把当前数字插入到最小堆，保证   最大堆的size>=最小堆的size
//为了保证有序，先插入最大堆，在弹出一个数字

class MedianFinder {
	//最大堆
	priority_queue<int> lo;
	//最小堆
	priority_queue<int, vector<int>, greater<int>> hi;


public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		lo.push(num);
		hi.push(lo.top());
		lo.pop();
		if (lo.size()<hi.size()) {
			lo.push(hi.top());
			hi.pop();
		}
	}

	double findMedian() {
		if (lo.size()>hi.size())
			return lo.top();
		else
			return (lo.top() + hi.top()) / 2.0;
	}
};

/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder* obj = new MedianFinder();
* obj->addNum(num);
* double param_2 = obj->findMedian();
*/

