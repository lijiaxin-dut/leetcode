#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//Given an integer array A, you partition the array into(contiguous) subarrays of length at most K.After partitioning, each subarray has their values changed to become the maximum value of that subarray.
//
//Return the largest sum of the given array after partitioning.
//
//
//
//Example 1:
//
//Input: A = [1, 15, 7, 9, 2, 5, 10], K = 3
//	Output : 84
//	Explanation : A becomes[15, 15, 15, 9, 10, 10, 10]
//


//dp[i]表示A[0]...A[i-1]的最大结果
//计算dp[i]时，考虑将A[i]于前面的最多k个数划分未一组

//dp[i]=max(dp[i],dp[i-j]+max(A[i-1],...A[i-j])*j)  j=1 to k


class Solution_1043 {
public:
	int maxSumAfterPartitioning(vector<int>& A, int K) {

		int n = A.size();
		vector<int>dp(n + 1, 0);
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			int cur_max = 0;
			for (int k = 1; k <= K&&i - k >= 0; k++) {
				cur_max = max(cur_max, A[i - k]);
				dp[i] = max(dp[i], dp[i - k] + cur_max*k);

			}
		}
		return dp[n];

	}
};