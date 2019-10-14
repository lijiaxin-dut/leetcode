#include<stack>

using namespace std;

//
//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//getMin() --Retrieve the minimum element in the stack.
//
//
//Example:
//
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> Returns - 3.
//minStack.pop();
//minStack.top();      --> Returns 0.
//minStack.getMin();   --> Returns - 2.


//ʹ������ջ��
//һ�����浱ǰ����Сֵ min_vals
//һ���������е�����   vals
//�и�С����ʱ���Ͳ��뵽min_vals
//���ڽ�ջ��Ԫ�����²���


class MinStack {
	stack<int>vals;
	stack<int>min_vals;
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		vals.push(x);
		if (min_vals.empty() || x<min_vals.top())
			min_vals.push(x);
		else
			min_vals.push(min_vals.top());

	}
	void pop() {
		vals.pop();
		min_vals.pop();

	}

	int top() {

		return vals.top();

	}

	int getMin() {
		return min_vals.top();

	}
};
