//Given integers n and k, find the lexicographically k - th smallest integer in the range from 1 to n.
//
//Note: 1 ≤ k ≤ n ≤ 109.
//
//	Example :
//
//	Input :
//	n : 13   k : 2
//
//	Output :
//	10
//
//	Explanation :
//	The lexicographical order is[1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.

//1.dfs依次生成数字

class Solution {
public:
	int findKthNumber(int n, int k) {
		int rs = 0;
		int cur_th = 0;
		for (int i = 1; i <= 9; i++) {
			cur_th++;
			dfs(n, i, k, rs, cur_th);
		}
		return rs;

	}
	void dfs(int n, int cur_val, int k, int &rs, int &cur_th) {
		if (cur_th>k || cur_val>n || rs != 0)
			return;
		if (cur_th == k) {
			rs = cur_val;
			return;
		}
		for (int i = 0; i <= 9; i++) {
			if (cur_val * 10 + i <= n) {
				cur_th++;
				dfs(n, cur_val * 10 + i, k, rs, cur_th);
			}
		}


	}
};