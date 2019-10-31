#include<vector>

using namespace std;

//A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
//
//For example, these are arithmetic sequence :
//
//1, 3, 5, 7, 9
//7, 7, 7, 7
//3, -1, -5, -9
//The following sequence is not arithmetic.
//
//1, 1, 2, 5, 7
//
//A zero - indexed array A consisting of N numbers is given.A slice of that array is any pair of integers(P, Q) such that 0 <= P < Q < N.
//
//	A slice(P, Q) of array A is called arithmetic if the sequence :
//A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic.In particular, this means that P + 1 < Q.
//
//	The function should return the number of arithmetic slices in the array A.


//dp[i][j]表示i->j是不是满足要求，并且记录差值
//if(dp[start][end-1].first==true&&A[end-1]-A[end]==dp[start][end-1].second)


//dp[i]表示到i的切片的个数
//dp[i]=dp[i-1]+1  if A[i]-A[i-1]==A[i-1]-A[i-2]
// [] [] [] [] [] [] [] [] [] [i-1] [i]
//如果A[i]-A[i-1]==A[i-1]-A[i-2] ，所有到i的切片都可以到j
//需要加上 i-2,i-1,i这一个即可



class Solution_413 {
public:
	int numberOfArithmeticSlices_dp_1(vector<int>& A) {
		int n = A.size();
		int rs = 0;
		vector<int>dp(n, 0);
		for (int i = 2; i<n; i++) {
			if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
				dp[i] = dp[i - 1] + 1;
			rs += dp[i];
		}
		return rs;
	}
	int numberOfArithmeticSlices(vector<int>& A) {
		int rs = 0;
		int n = A.size();
		vector<vector<pair<bool, int>>>dp(n, vector<pair<bool, int>>(n, make_pair(false, 0)));
		for (int start = 0; start<A.size() && start + 2<n; start++) {
			if (A[start] - A[start + 1] == A[start + 1] - A[start + 2]) {
				dp[start][start + 2].first = true;
				dp[start][start + 2].second = A[start] - A[start + 1];
				rs++;
			}
		}
		for (int length = 4; length <= n; length++) {
			for (int start = 0; start<n&&start + length - 1<n; start++) {
				int end = start + length - 1;
				if (dp[start][end - 1].first == true && A[end - 1] - A[end] == dp[start][end - 1].second) {
					dp[start][end].first = true;
					dp[start][end].second = dp[start][end - 1].second;
					rs++;
				}
			}
		}
		return rs;
	}
};