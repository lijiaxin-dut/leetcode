#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Input: [1, 4], 2
//	Output : 4
//	Explanation : At time point 1, Teemo starts attacking Ashe and makes Ashe be poisoned immediately.
//	This poisoned status will last 2 seconds until the end of time point 2.
//	And at time point 4, Teemo attacks Ashe again, and causes Ashe to be in poisoned status for another 2 seconds.
//	So you finally need to output 4.

//当前点的攻击结束时间与下一个攻击时间取较小值
//单独考虑最后一个攻击
//最后一个攻击直接加上时间即可


class Solution_495 {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		if (timeSeries.empty())
			return 0;

		int rs = 0;
		for (int i = 0; i<timeSeries.size() - 1; i++) {
			if (timeSeries[i] + duration <= timeSeries[i + 1]) {
				rs += duration;
			}
			else {
				rs += timeSeries[i + 1] - timeSeries[i];
			}
		}
		rs += duration;
		return rs;
	}
};