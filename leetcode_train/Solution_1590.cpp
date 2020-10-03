#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//
//给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空），使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。
//
//请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 - 1 。
//
//子数组 定义为原数组中连续的一组元素。
//
//

//假设 nums 的和除以 P，余数是 mod，
//如果 mod == 0，答案就是 0。
//如果 mod != 0，答案变成了找原数组中的最短连续子数组，
//使得其数字和除以 P，余数也是 mod。
//
//
//假设当前前缀和除以 P 的余数是 curmod，为了找到一段连续子数组对 P 的余数是 mod，我们需要找到一段前缀和，对 P 的余数是 targetmod。其中 targetmod 的求法是：
//
//如果 curmod >= mod，很简单：targetmod = curmod - mod；
//
//如果 curmod < mod，我们需要加上一个 P：targetmod = curmod - mod + P；
//
//	这样，我们可以保证，当前前缀和减去目标前缀和，剩余的数组对 P 的余数是 mod。我们只需要找最短的这样的数组就好。
//



class Solution {
public:
	int minSubarray(vector<int>& nums, int p) {
		int n = nums.size();
		long long sum = 0;
		long long mod = 0;
		for (auto i : nums) {
			sum += i;
		}
		mod = sum % p;
		if (mod == 0)
			return 0;
		unordered_map<int, int>m;
		m[0] = -1;
		sum = 0;
		int rs = n;
		for (int i = 0; i<n; i++) {
			sum += nums[i];
			sum = sum % p;
			m[sum] = i;
			int target_mod = sum >= mod ? sum - mod : sum - mod + p;
			if (m.count(target_mod)) {
				rs = min(rs, i - m[target_mod]);
			}
		}
		return rs == n ? -1 : rs;
	}
};