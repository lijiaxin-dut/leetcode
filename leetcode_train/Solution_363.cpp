#include<vector>
#include<set>
#include<algorithm>
using namespace std;


//Given a non - empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.
//
//Example:
//
//Input: matrix = [[1, 0, 1], [0, -2, 3]], k = 2
//	Output : 2
//	Explanation : Because the sum of rectangle[[0, 1], [-2, 3]] is 2,
//	and 2 is the max number no larger than k(k = 2).

//��һ�������У��ҵ����<=k��������
//ʹ��set���������
//�������set�д���>=sum-k�����֣�������ӽ�������it����lower_bound
//sum-it����һ�����С��k��subarray

//Ȼ�������е�ǰ׺�к�
//�õ����飬���������㷨����



class Solution_363 {
	int max_sum_sub_array_less_than_k(vector<int>&nums, int k) {
		int cur_sum = 0;
		set<int>sums;
		sums.insert(0);
		int rs = INT_MIN;
		for (int i = 0; i<nums.size(); i++) {
			cur_sum += nums[i];
			auto it = sums.lower_bound(cur_sum - k);
			if (it != sums.end()) {
				rs = max(rs, cur_sum - *it);
			}
			sums.insert(cur_sum);
		}
		return rs;

	}
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int m = matrix.size();
		if (m == 0)
			return 0;
		int n = matrix[0].size();
		int rs = -INT_MAX;
		for (int i = 0; i<n; i++) {
			vector<int>sum(m, 0);
			for (int j = i; j<n; j++) {
				for (int k = 0; k<m; k++) {
					sum[k] += matrix[k][j];
				}
				rs = max(rs, max_sum_sub_array_less_than_k(sum, k));
			}
		}
		return rs;
	}
};