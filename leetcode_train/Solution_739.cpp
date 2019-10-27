#include<iostream>
#include<vector>
#include<stack>

using namespace std;


//Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature.If there is no future day for which this is possible, put 0 instead.
//
//For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be[1, 1, 4, 2, 1, 1, 0, 0].
//
//Note: The length of temperatures will be in the range[1, 30000].Each temperature will be an integer in the range[30, 100].



//ջ���汣��Ԫ�أ���ջ����ջ�ͣ��¶�һ�ε���
//ÿ������һ���µ�Ԫ��ʱ����ǰ�¶���ջ��Ԫ�ؽ��бȽ�
//��ǰ�¶ȴ���ջ��Ԫ��ʱ�����ҵ��˵�һ������ջ���¶ȵ�ֵ
//ֱ����ǰ�¶�С��ջ��Ԫ��




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