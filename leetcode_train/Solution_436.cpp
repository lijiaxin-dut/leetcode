#include<map>
#include<vector>

using namespace std;

//
//Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.
//
//For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store - 1 for the interval i.Finally, you need output the stored value of each interval as an array.

//�����еĿ�ʼʱ�����map
//Ȼ�����ÿ������ʱ�䣬����lb����С�Ĵ��ڵ�ǰ����ʱ��Ŀ�ʼʱ��

class Solution {
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		map<int, int>m;//����ʱ��-index
		for (int i = 0; i<intervals.size(); i++) {
			auto &one_interval = intervals[i];
			m.insert(make_pair(one_interval[0], i));
		}
		vector<int>rs;
		for (auto &one_interval : intervals) {
			auto lb = m.lower_bound(one_interval[1]);
			if (lb == m.end())
				rs.push_back(-1);
			else
				rs.push_back(lb->second);
		}
		return rs;
	}
};