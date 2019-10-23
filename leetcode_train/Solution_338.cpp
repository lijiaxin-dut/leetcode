#include<vector>

using namespace std;

//Given a non negative integer number num.For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
//
//Example 1:
//
//Input: 2
//	Output : [0, 1, 1]

//使用mark记录已经找到的数字的结果
//查询已知的结果


//dp[i]=dp[i&(i-1)]+1


class Solution_338 {

	
	int count_one(int n, vector<int>&hash_map) {
		int rs = 0;
		while (n != 0) {
			if (hash_map[n] != 0) {
				rs += hash_map[n];
				break;
			}
			n = n&(n - 1);
			rs++;
		}
		hash_map[n] = rs;
		return rs;
	}
public:
	vector<int> countBits(int num) {
		vector<int>hash_map(num + 1, 0);
		vector<int>rs;
		for (int i = 0; i <= num; i++) {
			rs.push_back(count_one(i, hash_map));
		}
		return rs;


	}

	vector<int> countBits_dp(int num) {
		vector<int>dp(num + 1, 0);
		for (int i = 1; i <= num; i++) {
			dp[i] = dp[i&(i - 1)] + 1;
		}
		return dp;
	}
};