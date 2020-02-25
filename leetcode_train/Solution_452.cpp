#include<map>
#include<vector>
#include<algorithm>
using namespace std;



//There are a number of spherical balloons spread in two - dimensional space.For each balloon, provided input is the start and end coordinates of the horizontal diameter.Since it's horizontal, y-coordinates don't matter and hence the x - coordinates of start and end of the diameter suffice.Start is always smaller than end.There will be at most 104 balloons.
//
//An arrow can be shot up exactly vertically from different points along the x - axis.A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend.There is no limit to the number of arrows that can be shot.An arrow once shot keeps travelling up infinitely.The problem is to find the minimum number of arrows that must be shot to burst all balloons.
//
//Example:
//
//Input:
//[[10, 16], [2, 8], [1, 6], [7, 12]]
//
//Output :
//	2
//
//	Explanation :
//	One way is to shoot one arrow for example at x = 6 (bursting the balloons[2, 8] and [1, 6]) and another arrow at x = 11 (bursting the other two balloons).


//按照结束坐标从小到达排序


class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		if (points.empty())
			return 0;
		sort(points.begin(), points.end(), [](vector<int>a, vector<int>b) {return a[1]<b[1]; });
		int cur_index = 0;
		int rs = 1;
		int n = points.size();
		for (int i = 1; i<n; i++) {
			if (points[i][0]>points[cur_index][1]) {
				cur_index = i;
				rs++;
			}
		}
		return rs;
	}
};