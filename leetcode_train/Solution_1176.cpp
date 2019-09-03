#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//A dieter consumes calories[i] calories on the i - th day.For every consecutive sequence of k days, they look at T, the total calories consumed during that sequence of k days :
//
//If T < lower, they performed poorly on their diet and lose 1 point;
//If T > upper, they performed well on their diet and gain 1 point;
//Otherwise, they performed normally and there is no change in points.

//考虑连续滑动的窗口，窗口长度不发生变化

class Solution_1176 {
public:
	int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
		int point = 0;
		int T = 0;
		for (int i = 0; i<k; i++) {
			T += calories[i];
		}
		int left = 0;
		int right = k - 1;
		if (T<lower)
			point -= 1;
		if (T>upper)
			point += 1;
		right++;
		//窗口不断向右移动
		while (right<calories.size()) {
			T -= calories[left];
			T += calories[right];
			left++;
			right++;
			if (T<lower)
				point -= 1;
			if (T>upper)
				point += 1;
		}
		return point;
	}
};
