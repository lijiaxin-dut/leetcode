#include<vector>
#include<algorithm>

using namespace std;

//在代号为 C - 137 的地球上，Rick 发现如果他将两个球放在他新发明的篮子里，它们之间会形成特殊形式的磁力。Rick 有 n 个空的篮子，第 i 个篮子的位置在 position[i] ，Morty 想把 m 个球放到这些篮子里，使得任意两球间 最小磁力 最大。
//
//已知两个球如果分别位于 x 和 y ，那么它们之间的磁力为  | x - y | 。
//
//给你一个整数数组 position 和一个整数 m ，请你返回最大化的最小磁力。
//
//


//二分搜索
//给一个mid值，判断能否分成最多m-1块，使得最大引力为mid


class Solution {
	bool can_split(vector<int>&nums, int m, int mid) {
		int left = 0;
		int size = 1;
		for (int i = 0; i<nums.size(); i++) {
			if (nums[i] - nums[left]>mid) {
				size++;
				left = i;
			}
		}
		return size < m;
	}
public:
	int maxDistance(vector<int>& position, int m) {
		sort(position.begin(), position.end());
		int left = 1;
		int right = 1e9;
		bool is_split = can_split(position, m, 3);
		while (left<right) {
			int mid = left + (right - left) / 2;
			bool is_split = can_split(position, m, mid);
			if (is_split == true) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
};