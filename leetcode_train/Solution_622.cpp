#include<vector>

using namespace std;

//head_index 头部的位置
//count   元素的个数
//capacity  队列的容量


//入队列的index:(head_index + count)%capacity
//尾部的index：(head_index + count - 1)%capacity
//出队列的操作:(head_index+1)%capacity

class MyCircularQueue {
	vector<int>queue;
	int head_index;
	int count;
	int capacity;
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		queue.resize(k);
		count = 0;
		capacity = k;
		head_index = 0;

	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (capacity == count)
			return false;
		queue[(head_index + count) % capacity] = value;
		count += 1;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (count == 0)
			return false;
		head_index = (head_index + 1) % capacity;
		count -= 1;
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if (count == 0)
			return -1;
		return queue[head_index];
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (count == 0)
			return -1;
		return queue[(head_index + count - 1) % capacity];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return count == 0;

	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		return count == capacity;
	}
};

/**
* Your MyCircularQueue object will be instantiated and called as such:
* MyCircularQueue* obj = new MyCircularQueue(k);
* bool param_1 = obj->enQueue(value);
* bool param_2 = obj->deQueue();
* int param_3 = obj->Front();
* int param_4 = obj->Rear();
* bool param_5 = obj->isEmpty();
* bool param_6 = obj->isFull();
*/