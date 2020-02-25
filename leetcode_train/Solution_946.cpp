#include<vector>
#include<stack>

using namespace std;

//Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.
//
//
//
//Example 1:
//
//Input: pushed = [1, 2, 3, 4, 5], popped = [4, 5, 3, 2, 1]
//	Output : true
//	Explanation : We might do the following sequence :
//	   push(1), push(2), push(3), push(4), pop() -> 4,
//		   push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1


//̰��
//����һ��stack
//ÿ����stack��pushһ�����ֺ�
//��poped�н��бȽϣ������ͬ��popped index����ƶ�
//s����

//�ж����s�Ƿ�Ϊ��

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		int pop_index = 0;
		stack<int>s;
		for (int i = 0; i<pushed.size(); i++) {
			s.push(pushed[i]);
			while (!s.empty() && s.top() == popped[pop_index]) {
				pop_index++;
				s.pop();
			}
		}
		return s.empty();
	}
};