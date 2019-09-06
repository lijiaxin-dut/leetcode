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

//���Ȱ�����������ֵ�������������
//���ϵĽ����غϵ�����ϲ�����һ������
//���ܺϲ��Ϳ�һ���µ�����



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
			//û�з���overlap
			if (rs.back()[1]<intervals[i][0]) {
				rs.push_back(intervals[i]);
			}
			//����overlap���������һ��������Ҷ˵�
			else {
				rs.back()[1] = max(rs.back()[1], intervals[i][1]);
			}
		}
		return rs;
	}
};
