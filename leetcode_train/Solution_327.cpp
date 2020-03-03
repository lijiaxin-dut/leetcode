#include<vector>
#include<set>
#include<set>

using namespace std;

//Given an integer array nums, return the number of range sums that lie in[lower, upper] inclusive.
//Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j(i ≤ j), inclusive.
//
//Note:
//A naive algorithm of O(n2) is trivial.You MUST do better than that.

//使用multiset保存所有的求和
//得到一个新的求和时，希望找到一个 old_sum
//lb<=sum-old_sum<=up
//->sum-ub=< old_sum <=sum-lb
//需要计算有多少个sum满足这个条件
//lower_bound(sum - upper)  返回第一个>=sum-upper 的位置
//upper_bound(sum - lower)  返回第一个>sum-lower  的位置
//两个位置做差值，找到多少个满足条件的old_sum

//插入0为了考虑sum[0,j]满足题意的情况


//使用归并排序，对所有的前缀和进行排序

//在merge的过程中，找到第一个sums[j]-sums[i]>=lower的位置
//找到第一个sums[k]-sums[i]>upper的位置
//k-j就是对于i的结果

class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		int n = nums.size();
		multiset<long long>sums;
		long long sum = 0;
		int rs = 0;
		sums.insert(0);
		for (int i = 0; i<n; i++) {
			sum += nums[i];
			rs += distance(sums.lower_bound(sum - upper), sums.upper_bound(sum - lower));
			sums.insert(sum);
		}
		return rs;
	}

	long rs = 0;
	vector<long>aux;
public:
	int countRangeSum_merge(vector<int>& nums, int lower, int upper) {
		int n = nums.size();
		if (n == 0)
			return 0;
		vector<long>sums(n + 1, 0);
		for (int i = 0; i<n; i++)
			sums[i + 1] = sums[i] + nums[i];
		aux.resize(n + 1, 0);
		merge(sums, 0, n, lower, upper);
		return rs;
	}
	void merge(vector<long>&sums, int left, int right, int l, int u) {
		if (left<right) {
			int mid = left + (right - left) / 2;
			merge(sums, left, mid, l, u);
			merge(sums, mid + 1, right, l, u);
			merge_help(sums, left, mid, right, l, u);
		}
	}
	void merge_help(vector<long>&sums, int left, int mid, int right, int l, int u) {
		int first_greater_equal_lower = mid + 1;
		int first_greater_upper = mid + 1;

		for (int i = left; i <= mid; i++) {
			while (first_greater_equal_lower <= right&&sums[first_greater_equal_lower] - sums[i]<l)
				first_greater_equal_lower++;
			while (first_greater_upper <= right&&sums[first_greater_upper] - sums[i] <= u)
				first_greater_upper++;
			rs += first_greater_upper - first_greater_equal_lower;
		}

		int i = left;
		int j = mid + 1;
		for (int cur_index = left; cur_index <= right; cur_index++) {
			if (i == mid + 1)
				aux[cur_index] = sums[j++];
			else if (j == right + 1)
				aux[cur_index] = sums[i++];
			else if (sums[i] <= sums[j])
				aux[cur_index] = sums[i++];
			else
				aux[cur_index] = sums[j++];
		}
		for (int i = left; i <= right; i++)
			sums[i] = aux[i];





	}
};