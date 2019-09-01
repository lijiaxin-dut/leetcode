#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

//In an array A of 0s and 1s, how many non-empty subarrays have sum S?

//Input: A = [1, 0, 1, 0, 1], S = 2
//	Output : 4
//	Explanation :
//	The 4 subarrays are bolded below :
//	   [1, 0, 1, 0, 1]
//	   [1, 0, 1, 0, 1]
//	   [1, 0, 1, 0, 1]
//	   [1, 0, 1, 0, 1]

//计算前缀和
//Let P[i] = A[0] + A[1] + ... + A[i - 1]. ，前i索引的和，不包括i
//Then P[j + 1] - P[i] = A[i] + A[i + 1] + ... + A[j], //the sum of the subarray[i, j].
//Hence, we are looking for the number of i < j with P[j] - P[i] = S.
//计算任意两个前缀和之差，等于S即满足提议
//然后遍历前缀和数组，并记录遇到过的前缀+S，保存到map中
//之所以不包括P[i] = A[0] + A[1] + ... + A[i - 1]  不包括A[i] ，处理P[i]不存在的情况

class Solution_930 {
public:
	int numSubarraysWithSum(vector<int>& A, int S) {
		int n = A.size();
		vector<int>prex_sum(n+1, 0);
		for (int i = 0; i<n; i++) {
			prex_sum[i + 1] = prex_sum[i] + A[i];
		}
		int rs = 0;
		unordered_map<int, int>hash_map;
		for (auto &one_pre_sum : prex_sum) {
			if (hash_map.count(one_pre_sum) == 0) {
				hash_map[one_pre_sum + S]++;
			}
			else {
				hash_map[one_pre_sum + S]++;
				rs += hash_map[one_pre_sum];
			}
		}
		return rs;

	}
};


int main() {
	Solution_930 s;
	vector<int>A{ 1,0,1,0,1 };
	s.numSubarraysWithSum(A, 2);
}