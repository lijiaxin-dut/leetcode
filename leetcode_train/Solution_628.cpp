#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;
//
//Given an integer array, find three numbers whose product is maximum and output the maximum product.
//
//Example 1:
//
//Input: [1, 2, 3]
//	Output : 6
//
//
//	Example 2 :
//
//	Input : [1, 2, 3, 4]
//	Output : 24
//

//排序
//记录五个数


class Solution_628 {
public:
	int maximumProduct_1(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int rs1 = nums[0] * nums[1] * nums[n - 1];
		int rs2 = nums[n - 3] * nums[n - 2] * nums[n - 1];
		return max(rs1, rs2);
	}
	//线性扫面，记录最小的两个数和最大的三个数
	int maximumProduct(vector<int>& nums) {
		int min1 = INT_MAX;
		int min2 = INT_MAX;
		int max1 = INT_MIN;
		int max2 = INT_MIN;
		int max3 = INT_MIN;
		for (auto &one_num : nums) {
			if (one_num <= min1) {
				min2 = min1;
				min1 = one_num;
			}
			else if (one_num>min1&&one_num <= min2) {
				min2 = one_num;
			}

			if (one_num >= max1) {
				max3 = max2;
				max2 = max1;
				max1 = one_num;
			}
			else if (one_num >= max2) {
				max3 = max2;
				max2 = one_num;
			}
			else if (one_num >= max3) {
				max3 = one_num;
			}
		}
		return max(min1*min2*max1, max1*max2*max3);

	}


};