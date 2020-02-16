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


//�������ѱ�������
//���ѱ����Сһ�������
//��С�ѱ���ϴ�һ�������

//ʹ�ñ������ѵ�size>=��С�ѵ�size
//���ѣ�1 2 3  ��С�ѣ�  4 5   ��������������ѶѶ�
//���򷵻������Ѷ����/2

//����ʱ���ѵ�ǰ���ֲ��뵽��С�ѣ���֤   ���ѵ�size>=��С�ѵ�size
//Ϊ�˱�֤�����Ȳ������ѣ��ڵ���һ������

class MedianFinder {
	//����
	priority_queue<int> lo;
	//��С��
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

