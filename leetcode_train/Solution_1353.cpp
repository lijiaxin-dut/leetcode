#include<vector>
#include<queue>
#include<functional>
using namespace std;
//
//Given an array of events where events[i] = [startDayi, endDayi].Every event i starts at startDayi and ends at endDayi.
//
//You can attend an event i at any day d where startTimei <= d <= endTimei.Notice that you can only attend one event at any time d.
//
//Return the maximum number of events you can attend.

//遍历所有的天数

//优先队列，越小越优先

//如果某event在当前天数开始，将结束天数插入到优先队列中
//然后从队列中删除已经结束的event
//如果不为空，删除最早结束的event

class Solution {
public:
	int maxEvents(vector<vector<int>>& A) {
		priority_queue <int, vector<int>, greater<int>> pq;
		sort(A.begin(), A.end());
		int i = 0, res = 0, n = A.size();
		for (int d = 1; d <= 100000; ++d) {
			while (i < n && A[i][0] == d)
				pq.push(A[i++][1]);
			while (pq.size() && pq.top() < d)
				pq.pop();
			if (pq.size()) {
				pq.pop();
				++res;
			}
		}
		return res;
	}
};

