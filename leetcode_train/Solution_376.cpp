#include<vector>
#include<algorithm>
using namespace std;


//在数组中找到最长的摆动序列


//p[i]表示到i的最后差值为正数    上一个为负数的+1
//q[i]表示到i的最后差值为负数	 上一个为正数的+1


class Solution_376 {
public:

	int wiggleMaxLength_(vector<int>& nums) {

		if (nums.empty())
			return 0;
		int n = nums.size();
		vector<int>p(n, 1);//p[i]表示到i的最后差值为正数
		vector<int>q(n, 1);//q[i]表示到i的最后差值为负数 
		for (int i = 1; i<n; i++) {
			for (int j = 0; j<i; j++) {
				if (nums[i]>nums[j])
					p[i] = max(p[i], q[j] + 1);
				else if (nums[i]<nums[j])
					q[i] = max(q[i], p[j] + 1);
			}
		}

		return max(p[n - 1], q[n - 1]);

	}


	int wiggleMaxLength(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int rs = 1;
		int length = 1;
		dfs(rs, nums, 0, true, length);
		dfs(rs, nums, 0, false, length);
		return rs;
	}

	void dfs(int &rs, vector<int>&nums, int last_index, bool last_sign, int &length) {
		if (last_index == nums.size())
			return;
		for (int i = last_index + 1; i<nums.size(); i++) {
			if (nums[i]>nums[last_index] && last_sign == false || nums[i]<nums[last_index] && last_sign == true) {
				length++;
				rs = max(rs, length);
				dfs(rs, nums, i, !last_sign, length);
				length--;
			}
		}

	}

};