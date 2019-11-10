
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

//ʹ��multi���滬�����ڵĴ�С
//ÿ��ɾ��ʱ��ʹ��find���Һ�ɾ��
//rbgein()����set�е����ֵ




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
};