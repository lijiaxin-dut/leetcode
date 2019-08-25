#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Description

//Given an array with n objects colored red, white or blue, sort them in - place so that objects of 
//the same color are adjacent, with the colors in the order red, white and blue.
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//Note: You are not suppose to use the library's sort function for this problem.


//使用两个索引，低位置的索引表示0可以放置的位置，高位置的索引表示2可以放置的位置，记录已经放置好的2的个数，
//用来提前结束循环

class Solution_75 {
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() <= 1)
			return;
		int hi = nums.size() - 1;
		int lo = 0;
		int hi_size = 0;
		for (int i = 0; i<nums.size() - hi_size; i++)
		{
			//如果时2，放到高位置
			if (nums[i] == 2)
			{
				swap(nums[i], nums[hi--]);
				hi_size++;
				//交换后当前位置可能是0，可能是1，需要重新判断
				i--;
			}
			//如果时0，放到低位置
			//交换后当前位置一定时0
			else if (nums[i] == 0)
			{
				swap(nums[i], nums[lo++]);
			}
		}

	}
};
//int main() {
//	Solution_75 s;
//	vector<int>color{ 2};
//	s.sortColors(color);
//}