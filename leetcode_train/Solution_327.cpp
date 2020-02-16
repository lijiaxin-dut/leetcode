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
};