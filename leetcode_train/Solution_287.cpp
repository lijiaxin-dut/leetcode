#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
// prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
// find the duplicate one.


class Solution_287 {
public:
	int findDuplicate_binary_search(vector<int>& nums) {
		//一共只有n个数字，给定一个数k，计算<=k的元素的个数
		//当最小k满足count(<=k)>k  ，k就是重复的元素
		int min = 1;
		int max = nums.size() - 1;//共有n个元素
		while (min<max) {
			int mid = (max + min) / 2;
			int count = 0;
			for (int i = 0; i<nums.size(); i++) {
				if (nums[i] <= mid)
					count++;
			}
			//mid一定不是重复的数组
			if (count <= mid)
				min = mid + 1;
			//mid可能是重复的数组，需要考虑mid
			else
				max = mid;
		}
		return min;
	}
	int findDuplicate(vector<int>& nums) {
		//快慢指针
		//数组中每个元素有两个属性，index和value,value视为指针，指向后面的位置

		//有重复数字时，可以认为链表中存在环，环的起点就是重复的数字
		//对于数组 A = [2, 6, 4, 1, 3, 1, 5]
		//	index 0, 1, 2, 3, 4, 5, 6
		//	value:2, 6, 4, 1, 3, 1, 5
		//	索引是什么？ 索引是指针的相对位置 / 偏移量
		//	那么value 是什么？ 下一个位置的地址
		//	那么这个数组就可以转换为 : 0 - > 2 - > 4 -> 3 -> 1 -> 6 -> 5->
		//  [1 - >6-> 5 ->1 链表环] 可以看到这就是一个有环的链表
		int fast = 0;
		int slow = 0;
		do {
			fast = nums[nums[fast]];
			slow = nums[slow];
		} while (fast != slow);
		fast = 0;
		while (fast != slow) {
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}
};