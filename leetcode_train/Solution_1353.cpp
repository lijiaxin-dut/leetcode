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

//�������е�����

//���ȶ��У�ԽСԽ����

//���ĳevent�ڵ�ǰ������ʼ���������������뵽���ȶ�����
//Ȼ��Ӷ�����ɾ���Ѿ�������event
//�����Ϊ�գ�ɾ�����������event

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

