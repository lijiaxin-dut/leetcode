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

//��ǰ��Ĺ�������ʱ������һ������ʱ��ȡ��Сֵ
//�����������һ������
//���һ������ֱ�Ӽ���ʱ�伴��


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