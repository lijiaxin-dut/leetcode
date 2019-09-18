#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

class Solution_611 {
public:
	int triangleNumber(vector<int>& nums) {
		int rs = 0;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		for (int i = 0; i<n; i++) {
			for (int j = i + 1; j<n; j++) {
				int left = j + 1;
				int right = n - 1;
				int sum = nums[i] + nums[j];
				//找到恰好小于sum的位置
				while (left <= right) {
					int mid = (left + right) / 2;
					if (sum>nums[mid]) {
						left = mid + 1;
					}
					else {
						right = mid - 1;
					}
				}
				rs += right - j;
			}
		}
		return rs;

	}
};