#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//You are given a circular array nums of positive and negative integers. 
//If a number k at an index is positive, then move forward k steps. 
//Conversely, if it's negative (-k), move backward k steps. Since the array is circular, 
//you may assume that the last element's next element is the first element, 
//and the first element's previous element is the last element.

//Determine if there is a loop(or a cycle) in nums.A cycle must start and end at the same index and 
//the cycle's length > 1. Furthermore, movements in a cycle must all follow a single direction. 
//In other words, a cycle must not consist of both forward and backward movements.


class Solution {
public:
	int get_next_index(int i, vector<int>& nums) {
		int new_index = i + nums[i];
		int n = nums.size();
		if (new_index >= n)
			return new_index%n;
		while (new_index<0)
			new_index = new_index + n;
		return new_index;
	}
public:
	//两个指针，一个每次向前走一步，一个每次向前走两步
	//如果每次都是正方向走，并且最后相遇
	//就找到了环，但是要考虑自环的可能性

	//如果不能构成环，在结束时，将数组修改为0
	bool circularArrayLoop_o_1(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i<n; i++) {
			if (nums[i] == 0)
				continue;
			int slow = i, fast = get_next_index(i, nums);
			while (nums[i] * nums[fast]>0 && nums[i] * nums[get_next_index(fast, nums)]>0) {
				if (slow == fast) {
					if (fast == get_next_index(fast, nums))
						break;
					return true;
				}
				slow = get_next_index(slow, nums);
				fast = get_next_index(get_next_index(fast, nums), nums);
			}
			slow = i;
			int cur_i = nums[i];
			while (cur_i*nums[slow]>0) {
				int next = get_next_index(slow, nums);
				nums[slow] = 0;
				slow = next;
			}
		}
		return false;
	}

	bool circularArrayLoop(vector<int>& nums) {
		int n = nums.size();
		vector<bool>mark(n, false);
		for (int i = 0; i<n; i++) {
			if (mark[i] == true)
				continue;
			bool is_forward = true;
			if (nums[i]<0)
				is_forward = false;
			mark[i] = true;
			unordered_set<int>partial_rs;
			partial_rs.insert(i);
			int pre_index = i;
			while (true) {
				int next_index = pre_index + nums[pre_index];
				//确保next_index合法
				if (next_index >= n)
					next_index = next_index%n;
				while (next_index<0)
					next_index = next_index + n;
				//如果不能产生环，直接break
				if ((is_forward == false && nums[next_index]>0) || (is_forward&&nums[next_index]<0) || nums[next_index] % n == 0 || nums[next_index] == 0)
					break;
				if (partial_rs.find(next_index) != partial_rs.end())
					return true;

				mark[next_index] = true;
				partial_rs.insert(next_index);


				pre_index = next_index;
			}



		}
		return false;

	}
};