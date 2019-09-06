#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given a collection of intervals, merge all overlapping intervals.
//
//Example 1:
//
//Input: [[1, 3], [2, 6], [8, 10], [15, 18]]
//	Output : [[1, 6], [8, 10], [15, 18]]
//	Explanation : Since intervals[1, 3] and [2, 6] overlaps, merge them into[1, 6].

//首先按照区间左侧的值对区间进行排序
//不断的将有重合的区间合并到上一个区间
//不能合并就开一个新的区间



class Solution_56 {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() <= 1)
			return intervals;
		sort(intervals.begin(), intervals.end(), [](vector<int>a, vector<int>b) {return a[0]<b[0]; });
		int n = intervals.size();
		vector<vector<int>>rs;
		rs.push_back(intervals[0]);
		for (int i = 1; i<intervals.size(); i++) {
			//没有发生overlap
			if (rs.back()[1]<intervals[i][0]) {
				rs.push_back(intervals[i]);
			}
			//发生overlap，更新最后一个区间的右端点
			else {
				rs.back()[1] = max(rs.back()[1], intervals[i][1]);
			}
		}
		return rs;
	}
};
