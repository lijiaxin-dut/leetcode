#include<deque>
#include<vector>
#include<set>
using namespace std;


//Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.You can only see the k numbers in the window.Each time the sliding window moves right by one position.Return the max sliding window.
//
//Example:
//
//Input: nums = [1, 3, -1, -3, 5, 3, 6, 7], and k = 3
//	Output : [3, 3, 5, 5, 6, 7]
//	Explanation :
//
//	Window position                Max
//	-------------- - ---- -
//	[1  3 - 1] - 3  5  3  6  7       3
//	1[3 - 1 - 3] 5  3  6  7       3
//	1  3[-1 - 3  5] 3  6  7       5
//	1  3 - 1[-3  5  3] 6  7       5
//	1  3 - 1 - 3[5  3  6] 7       6
//	1  3 - 1 - 3  5[3  6  7]      7

//使用multi保存滑动窗口的大小
//每次删除时，使用find查找后删除
//rbgein()返回set中的最大值

//begin()返回set中的最小值


class Solution_239 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (nums.size() == 0)
			return{};
		multiset<int>s;
		for (int i = 0; i<k; i++)
			s.insert(nums[i]);
		vector<int>rs;
		rs.push_back(*s.rbegin());
		int left = 0;
		for (int i = k; i<nums.size(); i++) {
			s.erase(s.find(nums[left++]));
			s.insert(nums[i]);
			rs.push_back(*s.rbegin());
		}
		return rs;
	}
	vector<int> maxSlidingWindow_deque(vector<int>& nums, int k) {
		if (k == 0 || nums.empty())
			return{};
		deque<int>q;
		for (int i = 0; i<k; i++) {
			while (!q.empty() && nums[i]>nums[q.back()])
				q.pop_back();
			q.push_back(i);
		}
		vector<int>rs;
		rs.push_back(nums[q.front()]);
		for (int i = k; i<nums.size(); i++) {
			while (!q.empty() && nums[i]>nums[q.back()])
				q.pop_back();
			if (!q.empty() && q.front() <= i - k)
				q.pop_front();
			q.push_back(i);
			rs.push_back(nums[q.front()]);
		}

		return rs;
	}
};