#include<vector>
#include<algorithm>

using namespace std;

//集合 S 包含从1到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，导致集合丢失了一个整数并且有一个元素重复。
//给定一个数组 nums 代表了集合 S 发生错误后的结果。你的任务是首先寻找到重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
//示例 1:
//输入: nums = [1, 2, 2, 4]
//	输出 : [2, 3]
//

//排序，因为元素范围是1-n，遍历的过程中就在排序


class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i<n; i++) {
			while (i + 1 != nums[i] && nums[nums[i] - 1] != nums[i]) {
				swap(nums[nums[i] - 1], nums[i]);
			}
		}
		vector<int>rs;
		for (int i = 0; i<n; i++) {
			if (i + 1 != nums[i]) {
				rs = { nums[i],i + 1 };
				break;
			}
		}
		return rs;
	}
};