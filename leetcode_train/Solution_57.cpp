#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//Given a set of non - overlapping intervals, insert a new interval into the intervals(merge if necessary).
//
//You may assume that the intervals were initially sorted according to their start times.
//
//Example 1:
//
//Input: intervals = [[1, 3], [6, 9]], newInterval = [2, 5]
//	Output : [[1, 5], [6, 9]]
//	Example 2 :
//
//	Input : intervals = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]], newInterval = [4, 8]
//	Output : [[1, 2], [3, 10], [12, 16]]
//	Explanation : Because the new interval[4, 8] overlaps with[3, 5], [6, 7], [8, 10].
//


//剔除没有交集的部分，直接保存
//对于有交集的部分，所有开始时间的最小值，所有开始时间的最大值，构成一个新的interval


class Solution_57 {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>>left;
		vector<vector<int>>right;
		int s = newInterval[0];
		int e = newInterval[1];
		for (int i = 0; i<intervals.size(); i++) {
			if (intervals[i][1]<newInterval[0]) {
				left.push_back(intervals[i]);
			}
			else if (intervals[i][0]>newInterval[1]) {
				right.push_back(intervals[i]);
			}
			else {
				s = min(s, intervals[i][0]);
				e = max(e, intervals[i][1]);
			}
		}
		left.push_back({ s,e });
		left.insert(left.end(), right.begin(), right.end());
		return left;
	}
};