#include<stack>
#include<iostream>
using namespace std;

class MaxStack {
public:
	/** initialize your data structure here. */
	MaxStack() {}

	void push(int x) {
		s1.push(x);
		if (s2.empty())
			s2.push(x);
		else {
			if (x > s2.top())
				s2.push(x);
			else
				s2.push(s2.top());
		}

	}

	int pop() {
		int t = s1.top(); 
		s1.pop();
		s2.pop();
		return t;
	}

	int top() {
		return s1.top();
	}

	int peekMax() {
		return s2.top();
	}

	int popMax() {
		int mx = s2.top();
		stack<int> t;
		while (s1.top() != mx) {
			t.push(s1.top()); 
			s1.pop();
			s2.pop();
		}
		s1.pop(); 
		s2.pop();
		while (!t.empty()) {
			push(t.top()); 
			t.pop();
		}
		return mx;
	}
	stack<int> s1, s2;
private:
	
};

