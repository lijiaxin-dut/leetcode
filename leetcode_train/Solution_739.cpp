#include<iostream>
#include<vector>
#include<stack>

using namespace std;


//Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature.If there is no future day for which this is possible, put 0 instead.
//
//For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be[1, 1, 4, 2, 1, 1, 0, 0].
//
//Note: The length of temperatures will be in the range[1, 30000].Each temperature will be an integer in the range[30, 100].



//栈里面保存元素，从栈顶到栈低，温度一次递增
//每次遇到一个新的元素时，当前温度与栈顶元素进行比较
//当前温度大于栈顶元素时，就找到了第一个大于栈顶温度的值
//直到当前温度小于栈顶元素




class Solution_739 {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		stack<int>s;
		vector<int>rs(T.size(), 0);
		for (int i = 0; i<T.size(); i++) {
			while (!s.empty() && T[i]>T[s.top()]) {
				rs[s.top()] = i - s.top();
				s.pop();
			}
			s.push(i);
		}

		return rs;




	}
};