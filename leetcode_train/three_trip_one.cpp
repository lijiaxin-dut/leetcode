#include<vector>
#include<iostream>
using namespace std;


class TripleInOne {
	int stack_size;//
	vector<int>s;
	vector<int>each_size;
	vector<int>each_end;
public:
	TripleInOne(int stackSize) {
		stack_size = stackSize;
		each_size.resize(3, 0);
		each_end.resize(3);
		s.resize(3 * stack_size);
		for (int i = 0; i<3; i++) {
			each_end[i] = i*stack_size;
		}
	}

	void push(int stackNum, int value) {
		if (each_size[stackNum] == stack_size)
			return;
		each_size[stackNum]++;
		s[each_end[stackNum]] = value;
		each_end[stackNum]++;
	}

	int pop(int stackNum) {
		if (each_size[stackNum] == 0)
			return -1;
		each_size[stackNum]--;
		int val = s[--each_end[stackNum]];
		return val;
	}

	int peek(int stackNum) {
		if (each_size[stackNum] == 0)
			return -1;
		return s[each_end[stackNum] - 1];
	}

	bool isEmpty(int stackNum) {
		return each_size[stackNum] == 0;
	}
};
