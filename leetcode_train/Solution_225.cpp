#include<queue>

using namespace std;
//
//Implement the following operations of a stack using queues.
//
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//empty() --Return whether the stack is empty.

//每次插入时，都将队列中的元素重新插入，使得新插入的元素在最开始的位置



class MyStack {
	queue<int>q;

public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		queue<int>t;
		while (!q.empty()) {
			t.push(q.front());
			q.pop();
		}
		q.push(x);
		while (!t.empty()) {
			q.push(t.front());
			t.pop();
		}

	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int return_rs = q.front();
		q.pop();
		return return_rs;
	}

	/** Get the top element. */
	int top() {

		return q.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return  q.empty();
	}
};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack* obj = new MyStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* bool param_4 = obj->empty();
*/