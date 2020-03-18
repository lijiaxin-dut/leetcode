#include<vector>

using namespace std;


//滑动窗口，窗口右边界依次变大


class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>>rs;
		int left = 1;
		int right = 2;
		int mid = (target + 1) / 2;
		int sum = left + right;
		while (left<mid) {
			if (sum<target) {
				right++;
				sum += right;
			}
			else if (sum>target) {
				sum -= left;
				left++;
			}
			else {
				vector<int>t;
				for (int i = left; i <= right; i++) {
					t.push_back(i);
				}
				rs.push_back(t);
				sum -= left;
				left++;
			}
		}
		return rs;
	}
};