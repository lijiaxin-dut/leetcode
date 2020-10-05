#include<vector>
#include<algorithm>

using namespace std;

//给你一个整数数组 arr 和一个目标值 target ，请你返回一个整数 value ，使得将数组中所有大于 value 的值变成 value 后，数组的和最接近  target （最接近表示两者之差的绝对值最小）。
//
//如果有多种使得和最接近 target 的方案，请你返回这些整数中的最小值。
//
//请注意，答案不一定是 arr 中的数字。

//穷举可变数字的范围，然后找一个最优的结

class Solution {
public:
	int findBestValue(vector<int>& arr, int target) {
		sort(arr.begin(), arr.end());
		int n = arr.size();
		vector<int>pre_sum(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			pre_sum[i] = pre_sum[i - 1] + arr[i - 1];
		}
		int upper = *max_element(arr.begin(), arr.end());
		int rs = 0;
		int diff = target;
		for (int i = 1; i <= upper; i++) {
			auto it = lower_bound(arr.begin(), arr.end(), i);
			int cur = pre_sum[it - arr.begin()] + (arr.end() - it)*i;
			if (abs(cur - target)<diff) {
				diff = abs(cur - target);
				rs = i;
			}
		}
		return rs;
	}
};