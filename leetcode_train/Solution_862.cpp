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

//1.将前缀和放入优先队列中，得到一个前缀和后
//与top元素比较，进行判断
//2.计算所有的前缀和
//依次遍历前缀和，并且放入deque中
//每次遇到一个前缀和时，不断的与d.top()进行比较
//如果满足条件，就弹出，
//并且deque中是一个递增栈
//如果当前i的前缀和是10
//deque的尾部是15
//15可以从deque中弹出，后面的前缀和与10比较的结果一定比15好


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
