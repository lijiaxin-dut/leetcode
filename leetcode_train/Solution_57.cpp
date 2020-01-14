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


//�ҵ����ʵ�λ�ý��в��룬��intervals[i][1]>newInterval[0]������Ҳ�����ֱ����������
//Ȼ���жϵ�ǰλ����newInterval�Ĺ�ϵ���ж���û�н���
//��Ϊ�������
//Ȼ�����һ��λ�ã���ʼ�ϲ�interval


class Solution_57 {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

		sort(intervals.begin(), intervals.end(), [](vector<int>a, vector<int>b) {return a[0]<b[0]; });
		int n = intervals.size();
		vector<vector<int>>rs;

		int next_index = 0;
		for (; next_index<n; next_index++) {
			if (intervals[next_index][1]<newInterval[0]) {
				rs.push_back(intervals[next_index]);
				continue;
			}
			else
				break;
		}

		if (next_index == n) {
			intervals.push_back(newInterval);
			return intervals;
		}

		if (intervals[next_index][0]>newInterval[1]) {
			rs.push_back(newInterval);
			rs.push_back(intervals[next_index]);

		}
		else if (intervals[next_index][0]<newInterval[0]) {
			rs.push_back(intervals[next_index]);
			rs.back()[1] = max(newInterval[1], intervals[next_index][1]);
		}
		else {
			rs.push_back(newInterval);
			rs.back()[1] = max(newInterval[1], intervals[next_index][1]);
		}

		for (int i = next_index + 1; i<intervals.size(); i++) {
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