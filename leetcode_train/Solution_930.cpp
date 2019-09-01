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

//����ǰ׺��
//Let P[i] = A[0] + A[1] + ... + A[i - 1]. ��ǰi�����ĺͣ�������i
//Then P[j + 1] - P[i] = A[i] + A[i + 1] + ... + A[j], //the sum of the subarray[i, j].
//Hence, we are looking for the number of i < j with P[j] - P[i] = S.
//������������ǰ׺��֮�����S����������
//Ȼ�����ǰ׺�����飬����¼��������ǰ׺+S�����浽map��
//֮���Բ�����P[i] = A[0] + A[1] + ... + A[i - 1]  ������A[i] ������P[i]�����ڵ����

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