#include<queue>
#include<vector>

using namespace std;


//Suppose LeetCode will start its IPO soon.In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO.Since it has limited resources, it can only finish at most k distinct projects before the IPO.Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.
//
//You are given several projects.For each project i, it has a pure profit Pi and a minimum capital of Ci is needed to start the corresponding project.Initially, you have W capital.When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
//
//To sum up, pick a list of at most k distinct projects from given projects to maximize your final capital, and output your final maximized capital.


//���ջ��Ѵ�С�������򣬼��뵽���ȶ�����
//ÿ�ε�������������������Ŀ
//������������������Ŀ�У�ѡ����������ִ��

//priority_queueĬ�����ѣ�ʹ��less

class Solution {
public:
	int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
		auto c1 = [](pair<int, int>a, pair<int, int>b) {return a.first>b.first; };
		auto c2 = [](pair<int, int>a, pair<int, int>b) {return a.second<b.second; };
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(c1)>pq(c1);//��С��
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(c2)>pqcap(c2);//����

		for (int i = 0; i<Profits.size(); i++) {
			pq.push(make_pair(Capital[i], Profits[i]));

		}
		int rs = 0;
		for (int i = 0; i<k; i++) {
			while (!pq.empty() && pq.top().first <= W) {
				pqcap.push(pq.top());
				pq.pop();
			}
			if (pqcap.empty())
				break;
			W += pqcap.top().second;
			pqcap.pop();
		}
		return W;

	}
};