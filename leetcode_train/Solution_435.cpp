#include<vector>
#include<algorithm>

using namespace std;

//Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non - overlapping.
//
//
//
//Example 1:
//
//Input: [[1, 2], [2, 3], [3, 4], [1, 3]]
//	Output : 1
//	Explanation : [1, 3] can be removed and the rest of intervals are non - overlapping.



//贪心，结束时间由小到大排序


class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](vector<int>a, vector<int>b) {return a[1]<b[1]; });
		int rs = 0;
		int cur_index = -INT_MAX;
		for (int i = 0; i<intervals.size(); i++) {
			if (cur_index <= intervals[i][0]) {
				rs++;
				cur_index = intervals[i][1];
			}
		}
		return intervals.size() - rs;
	}
};