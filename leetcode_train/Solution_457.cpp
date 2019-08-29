#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

//You are given a circular array nums of positive and negative integers. 
//If a number k at an index is positive, then move forward k steps. 
//Conversely, if it's negative (-k), move backward k steps. Since the array is circular, 
//you may assume that the last element's next element is the first element, 
//and the first element's previous element is the last element.

//Determine if there is a loop(or a cycle) in nums.A cycle must start and end at the same index and 
//the cycle's length > 1. Furthermore, movements in a cycle must all follow a single direction. 
//In other words, a cycle must not consist of both forward and backward movements.


class Solution_457 {
public:
	bool circularArrayLoop(vector<int>& nums) {
		int n = nums.size();
		vector<bool>global_mark(n, 0);
		for (int i = 0; i<nums.size(); i++) {
			//标记本轮中出现的index
			set<int>index;
			int start_index = i;
			if (global_mark[start_index] == 1)
				continue;
			index.insert(start_index);
			global_mark[start_index] = 1;
			while (true) {
				int step = nums[start_index];
				//跳过单个点循环,值是自身索引的倍数，或者符号不一致的点
				if (abs(step) % n == 0 || (step>0 && nums[i]<0) || (step<0 && nums[i]>0))
					break;
				start_index = (start_index + step) % n;
				if (start_index<0)
					start_index = start_index + n;
				//这个index出现过并且长度>1
				if (index.find(start_index) != index.end())
					return true;
				//这个index没有出现过，进行标记
				else
					index.insert(start_index);
				//标记遇到过的index
				global_mark[start_index] = 1;
				if (index.size()>n)
					break;

			}
		}
		return false;
	}
};

//int main() {
//	Solution_457 s;
//	vector<int>nums{1,1 };
//	s.circularArrayLoop(nums);
//}