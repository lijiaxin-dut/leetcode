#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;

//给你一个整数 num 。你可以对它进行如下步骤恰好 两次 ：
//
//选择一个数字 x(0 <= x <= 9).
//选择另一个数字 y(0 <= y <= 9) 。数字 y 可以等于 x 。
//将 num 中所有出现 x 的数位都用 y 替换。
//得到的新的整数 不能 有前导 0 ，得到的新整数也 不能 是 0 。
//令两次对 num 的操作得到的结果分别为 a 和 b 。
//
//请你返回 a 和 b 的 最大差值 。
//
//
//
//示例 1：
//
//输入：num = 555
//输出：888
//解释：第一次选择 x = 5 且 y = 9 ，并把得到的新数字保存在 a 中。
//第二次选择 x = 5 且 y = 1 ，并把得到的新数字保存在 b 中。
//现在，我们有 a = 999 和 b = 111 ，最大差值为 888


//找出第一个不是9的数字，修改它变为9
//如果第一个数字为1，找出后面不是0和1的数字，修改为0
//如果第一个数字不是1，将他修改为1


string change_value(string s, int start_index, char c, char to) {
	for (int i = start_index; i < s.size(); i++) {
		if (s[i] == c)
			s[i] = to;
	}
	return s;

}

class Solution {
public:
	int maxDiff(int num) {
		string nums = to_string(num);
		int max_value = num;
		int min_value = num;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != '9')
			{
				max_value = stoi(change_value(nums, i, nums[i], '9'));
				break;
			}
		}
		if (nums[0] == '1') {
			for (int i = 1; i < nums.size(); i++) {
				if (nums[i] != '0'&& nums[i] != '1') {
					min_value = stoi(change_value(nums, i, nums[i], '0'));
					break;
				}
			}
		}
		else {
			min_value = stoi(change_value(nums, 0, nums[0], '1'));

		}
		return abs(max_value - min_value);
	}
};
