#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

//Given four lists A, B, C, D of integer values, compute how many tuples(i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
//
//To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of - 228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.
//
//Example:
//
//Input:
//A = [1, 2]
//B = [-2, -1]
//C = [-1, 2]
//D = [0, 2]
//
//Output :
//	2
//
//	Explanation :
//	The two tuples are :
//1. (0, 0, 0, 1)->A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
//2. (1, 1, 0, 0)->A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0



//1.二分 n^3 log n
//2.把A和B的两两之和都求出来，在 HashMap 中建立两数之和跟其出现次数之间的映射，
//再遍历C和D中任意两个数之和，只要看哈希表存不存在这两数之和的相反数



class Solution_454 {
public:

	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int>hash_map_A_B;
		int N = A.size();
		for (int i = 0; i<N; i++) {
			for (int j = 0; j<N; j++) {
				hash_map_A_B[A[i] + B[j]]++;
			}
		}
		int rs = 0;
		for (int i = 0; i<N; i++) {
			for (int j = 0; j<N; j++) {
				int cur_sum = C[i] + D[j];
				if (hash_map_A_B.find(-cur_sum) != hash_map_A_B.end())
					rs += hash_map_A_B[-cur_sum];
			}
		}
		return rs;
	}

	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		sort(D.begin(), D.end());
		int rs = 0;
		int N = A.size();
		for (int i = 0; i<N; i++) {
			for (int j = 0; j<N; j++) {
				for (int k = 0; k<N; k++) {
					int three_sum = A[i] + B[j] + C[k];
					int lo = 0;
					int hi = N - 1;
					while (lo <= hi) {
						int mid = lo + (hi - lo) / 2;
						int sum = three_sum + D[mid];
						if (sum == 0) {
							int left = mid;
							int right = mid + 1;
							while (left >= 0 && D[left--] == D[mid])
								rs++;
							while (right<N&&D[right++] == D[mid])
								rs++;
							break;
						}
						else if (sum>0)
							hi = mid - 1;
						else
							lo = mid + 1;

					}
				}
			}
		}
		return rs;

	}
};