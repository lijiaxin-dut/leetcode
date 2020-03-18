#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;



//Return the length of the shortest, non - empty, contiguous subarray of A with sum at least K.
//
//If there is no non - empty subarray with sum at least K, return -1.
//
//
//
//Example 1:
//
//Input: A = [1], K = 1
//	Output : 1

//1.��ǰ׺�ͷ������ȶ����У��õ�һ��ǰ׺�ͺ�
//��topԪ�رȽϣ������ж�
//2.�������е�ǰ׺��
//���α���ǰ׺�ͣ����ҷ���deque��
//ÿ������һ��ǰ׺��ʱ�����ϵ���d.top()���бȽ�
//��������������͵�����
//����deque����һ������ջ
//�����ǰi��ǰ׺����10
//deque��β����15
//15���Դ�deque�е����������ǰ׺����10�ȽϵĽ��һ����15��


class Solution {
public:
	int shortestSubarray_deque(vector<int>& A, int K) {
		deque<int>d;
		int rs = INT_MAX;
		int n = A.size();
		vector<int>sum(n + 1, 0);
		for (int i = 0; i<n; i++)
			sum[i + 1] = sum[i] + A[i];
		for (int i = 0; i <= n; i++) {
			while (!d.empty() && sum[i] - sum[d.front()] >= K) {
				rs = min(rs, i - d.front());
				d.pop_front();
			}
			while (!d.empty() && sum[i] <= sum[d.back()])
				d.pop_back();
			d.push_back(i);
		}
		return rs == INT_MAX ? -1 : rs;
	}
	int shortestSubarray_queue(vector<int>& A, int K) {
		int n = A.size();
		auto compare = [](pair<int, int>a, pair<int, int>b) {
			return a.first>b.first;
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)>pq(compare);
		pq.push(make_pair(0, -1));
		int sum = 0;
		int rs = INT_MAX;
		for (int i = 0; i<n; i++) {
			sum += A[i];
			while (!pq.empty() && sum - pq.top().first >= K) {
				rs = min(rs, i - pq.top().second);
				pq.pop();
			}
			pq.push(make_pair(sum, i));
		}
		return rs == INT_MAX ? -1 : rs;

	}
};
