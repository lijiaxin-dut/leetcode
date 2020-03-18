#include<vector>
#include<unordered_map>
using namespace std;
//
//Given a list of non - negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to a multiple of k, that is, sums up to n*k where n is also an integer.
//
//
//
//Example 1:
//
//Input: [23, 2, 4, 6, 7], k = 6
//	Output : True
//	Explanation : Because[2, 4] is a continuous subarray of size 2 and sums up to 6.
//

//遍历数字，将前缀和放入set中，每次得到一个新的前缀和
//就按照k倍数，从高到低进行查找
//并且坐标相差至少为2
//为了表示从0开始的子数组，在set中插入0
class Solution {
public:
	bool checkSubarraySum_bf(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int>pre_sums(n + 1, 0);
		for (int i = 0; i<n; i++)
			pre_sums[i + 1] = pre_sums[i] + nums[i];

		for (int i = 0; i <= n; i++) {
			for (int j = i + 2; j <= n; j++) {
				if (pre_sums[j] - pre_sums[i] == k || (k != 0 && (pre_sums[j] - pre_sums[i]) % k == 0))
					return true;
			}
		}
		return false;


	}

	bool checkSubarraySum(vector<int>& nums, int k) {
		int n = nums.size();
		if (n <= 1)
			return false;
		for (int i = 1; i<n; i++)
			if (nums[i - 1] == 0 && nums[i] == 0)
				return true;
		if (k == 0)
			return false;
		if (k<0)
			k = -k;
		unordered_map<int, int>hash_map;
		hash_map.insert(make_pair(0, -1));
		int sum = 0;
		for (int i = 0; i<n; i++) {
			sum += nums[i];
			for (int j = (sum / k)*k; j >= k; j = j - k) {
				if (hash_map.find(sum - j) != hash_map.end() && i - hash_map[sum - j] >= 2)
					return true;
			}
			hash_map.insert(make_pair(sum, i));
		}
		return false;

	}

};

