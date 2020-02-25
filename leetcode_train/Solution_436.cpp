#include<map>
#include<vector>

using namespace std;

//
//Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.
//
//For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store - 1 for the interval i.Finally, you need output the stored value of each interval as an array.

//把所有的开始时间放入map
//然后对于每个结束时间，调用lb找最小的大于当前结束时间的开始时间

class Solution {
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		map<int, int>m;//结束时间-index
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