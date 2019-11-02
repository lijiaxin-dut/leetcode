#include<queue>

using namespace std;
//
//Implement the following operations of a stack using queues.
//
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//empty() --Return whether the stack is empty.

//ÿ�β���ʱ�����������е�Ԫ�����²��룬ʹ���²����Ԫ�����ʼ��λ��



class MyStack {
	queue<int>rs;

public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		rs.push(x);
		for (int i = 0; i<(int)rs.size() - 1; i++) {
			rs.push(rs.front());
			rs.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int return_rs = rs.front();
		rs.pop();
		return return_rs;
	}

	/** Get the top element. */
	int top() {

		return rs.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return  rs.empty();
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