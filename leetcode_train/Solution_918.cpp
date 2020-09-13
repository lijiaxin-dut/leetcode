#include<vector>
#include<queue>
#include<deque>

using namespace std;

//
//给定一个由整数数组 A 表示的环形数组 C，求 C 的非空子数组的最大可能和。
//
//在此处，环形数组意味着数组的末端将会与开头相连呈环状。（形式上，当0 <= i < A.length 时 C[i] = A[i]，而当 i >= 0 时 C[i + A.length] = C[i]）
//
//	此外，子数组最多只能包含固定缓冲区 A 中的每个元素一次。（形式上，对于子数组 C[i], C[i + 1], ..., C[j]，不存在 i <= k1, k2 <= j 其中 k1 % A.length  = k2 % A.length）
//
//


//前缀和+单调队列


class Solution {
public:
	int maxSubarraySumCircular(vector<int>& A) {
		vector<int>pre_sums{ 0 };
		int n = A.size();
		for (int i = 0; i<n * 2; i++) {
			pre_sums.push_back(A[i%n] + pre_sums.back());
		}
		deque<int>q;
		q.push_back(0);
		int rs = INT_MIN;
		for (int i = 1; i <= n * 2; i++) {
			while (!q.empty() && i - q.front()> n) {
				q.pop_front();
			}
			rs = max(rs, pre_sums[i] - pre_sums[q.front()]);
			while (!q.empty() && pre_sums[i] <= pre_sums[q.back()]) {
				q.pop_back();
			}
			q.push_back(i);
		}
		return rs;
	}
};



int main() {
	vector <int>nums{5,-3,5};
	Solution s;
	s.maxSubarraySumCircular(nums);
}