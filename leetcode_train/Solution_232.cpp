#include<iostream>
#include<stack>

using namespace std;

//
//Implement the following operations of a queue using stacks.
//
//push(x) --Push element x to the back of queue.
//pop() --Removes the element from in front of queue.
//peek() --Get the front element.
//empty() --Return whether the queue is empty.



class MyQueue {
	stack<int>S;
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		stack<int>temp;
		while (!S.empty()) {
			temp.push(S.top());
			S.pop();
		}
		temp.push(x);
		while (!temp.empty()) {
			S.push(temp.top());
			temp.pop();
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int rs = S.top();
		S.pop();
		return rs;

	}

	/** Get the front element. */
	int peek() {
		return S.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return S.empty();
	}
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue* obj = new MyQueue();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->peek();
* bool param_4 = obj->empty();
*/