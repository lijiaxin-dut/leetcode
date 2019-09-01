#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given an integer array A, and an integer target, return the number of tuples i, j, k  
//such that i < j < k and A[i] + A[j] + A[k] == target.

//As the answer can be very large, return it modulo 10 ^ 9 + 7.

//3 <= A.length <= 3000
//0 <= A[i] <= 100
//0 <= target <= 300

//可以使用三个指针，当相等的情况发生时，注意计算个数


//优化：
//因为题目限定了每个数字的单位 [1,100]
//首先统计每个数字出现的次数
//然后遍历这100个数，两层循环
//for (int i = 0; i <= 100; i++) 
	//for (int j = i; j <= 100; j++)
	
//则第三个数字为 target-i-j
//过滤掉第三个数字不合法的情况
//分为四种情况

//i==j==k
//i==j&&j!=k
//i!=j&&j==k
//i!=j&&j!=k

class Solution_923 {
public:
	int threeSumMulti_1(vector<int>& A, int target) {
		sort(A.begin(), A.end());
		long long int mod = 1000000007ll;
		unsigned long long rs = 0;
		for (int i = 0; i<A.size(); i++) {
			int left = i + 1;
			int right = A.size() - 1;
			while (left<right) {
				if (A[i] + A[left] + A[right] == target) {
					if (A[left] == A[right]) {
						rs += (right - left + 1) * (right - left) / 2;
						rs %= mod;
						break;
					}
					else {
						rs++;
						rs %= mod;
						//处理相同的情况
						for (int j = right - 1; j>left; j--) {
							if (A[j] == A[right])
								rs++;
							else
								break;
						}
						//处理相同的情况
						for (int j = left + 1; j<right; j++) {
							if (A[j] == A[left])
								rs++;
							else
								break;
						}
						right--;
						left++;
					}
				}
				else if (A[i] + A[left] + A[right]>target) {
					right--;
				}
				else if (A[i] + A[left] + A[right]<target) {
					left++;
				}
			}

		}
		return rs;
	}
	int threeSumMulti(vector<int>& A, int target) {
		vector<unsigned long long>count(101, 0);
		for (const auto &a : A)
			count[a]++;
		unsigned long long int mod = 1000000007ll;
		unsigned long long rs = 0;
		for (int i = 0; i <= 100; i++) {
			for (int j = i; j <= 100; j++) {
				int k = target - i - j;
				if (k < 0 || k < j || k>100)
					continue;
				if (count[i] == 0 || count[j] == 0 || count[k] == 0)
					continue;
				if (i != j&&j != k)
					rs += count[i] * count[j] * count[k];
				else if (i == j&&j != k)
					rs += count[i] * (count[i] - 1) / 2 * count[k];
				else if (i != j && j == k)
					rs += count[i] * (count[j] - 1)*count[j] / 2;
				else
					rs += (count[i] - 2)*(count[i] - 1)*(count[i]) / 6;
				rs %= mod;
			}
		}
		return int(rs);
	}
};

//int main() {
//	vector<int>a{ 35,29,93,59,16,53,90,88,2,28,40,83,60,92,22,18,70,42,50,73,10,23,17,3,48,51,29,16,42,33,51,34,13,38,54,59,19,92,60,81,69,90,80,1,12,72,79,1,67,63,13,2,61,65,16,19,20,52,19,68,11,90,9,77,29,91,78,42,66,41,67,97,79,0,49,6,84,37,59,93,23,40,16,0,46,74,62,97,96,99,53,84,99,14,82,21,24,43,7,11,41,96,19,8,8,45,60,57,16,26,54,64,83,95,29,42,43,27,14,4,52,76,41,20,7,27,3,39,26,49,18,31,51,63,88,94,46,27,40,16,46,29,93,18,39,35,100,4,29,81,9,37,21,9,53,30,58,78,41,77,30,50,16,84,59,53,40,90,4,85,53,89,62,27,1,2,31,79,47,76,9,82,86,76,5,55,100,77,64,35,70,100,59,47,35,70,59,93,59,98,14,31,30,12,26,13,7,16,3,76,23,46,39,81,25,5,70,73,7,35,71,18,66,60,86,63,97,32,14,35,68,69,31,52,83,34,100,40,44,7,28,76,38,90,36,34,10,99,47,49,63,74,5,53,11,99,33,46,78,36,51,26,43,83,9,68,31,48,71,53,64,64,43,62,77,59,100,84,15,23,95,5,6,7,23,20,84,60,75,25,63,54,94,83,52,16,26,48,40,75 };
//	Solution_923 s;
//	s.threeSumMulti(a, 138);
//}