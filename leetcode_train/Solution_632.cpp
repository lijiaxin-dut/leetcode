﻿#include<vector>
#include<algorithm>
#include<unordered_map>
#include<sstream>

using namespace std;


//
//你有 k 个升序排列的整数列表。找到一个最小区间，使得 k 个列表中的每个列表至少有一个数包含在其中。
//
//我们定义如果 b - a < d - c 或者在 b - a == d - c 时 a < c，则区间[a, b] 比[c, d] 小。
//
//	示例：
//	输入：[[4, 10, 15, 24, 26], [0, 9, 12, 20], [5, 18, 22, 30]]
//	输出：[20, 24]
//	解释：
//	列表 1：[4, 10, 15, 24, 26]，24 在区间[20, 24] 中。
//	列表 2：[0, 9, 12, 20]，20 在区间[20, 24] 中。
//	列表 3：[5, 18, 22, 30]，22 在区间[20, 24] 中。
//	提示：
//	给定的列表可能包含重复元素，所以在这里升序表示 >= 。
//	1 <= k <= 3500
//	- 10^5 <= 元素的值  <= 10^5

//
//A是长度为n的集合
//B是每个元素index的映射
//如果列表集合为：
//0: [-1, 2, 3]
//1 : [1]
//2 : [1, 2]
//3 : [1, 1, 3]
//那么可以得到这样一个哈希映射
//- 1 : [0]
//1 : [1, 2, 3, 3]
//2 : [0, 2]
//3 : [0, 3]

//用B中的value去覆盖集合A
//滑动窗口


class Solution {

public:
	vector<int> smallestRange(vector<vector<int>>& nums) {
		int n = nums.size();
		int xMin = INT_MAX;
		int xMax = INT_MIN;
		unordered_map<int, vector<int>>indices;
		for (int i = 0; i<n; i++) {
			for (auto x : nums[i]) {
				indices[x].push_back(i);
				xMax = max(xMax, x);
				xMin = min(xMin, x);
			}
		}
		int bestLeft = xMin;
		int bestRight = xMax;
		int left = xMin;
		int right = xMin;
		vector<int>freq(n, 0);
		int inside = 0;
		while (right <= xMax) {
			if (indices.count(right)) {
				for (auto x : indices[right]) {
					freq[x]++;
					if (freq[x] == 1)
						inside++;
				}
				while (inside == n) {
					if (right - left<bestRight - bestLeft) {
						bestLeft = left;
						bestRight = right;
					}
					if (indices.count(left)) {
						for (auto x : indices[left]) {
							freq[x]--;
							if (freq[x] == 0)
								inside--;
						}
					}
					left++;
				}
			}
			right++;
		}
		return{ bestLeft, bestRight };
	}
};