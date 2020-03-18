#include<vector>
#include<algorithm>


using namespace std;


//There is a room with n bulbs, numbered from 1 to n, arranged in a row from left to right.Initially, all the bulbs are turned off.
//
//At moment k(for k from 0 to n - 1), we turn on the light[k] bulb.A bulb change color to blue only if it is on and all the previous bulbs(to the left) are turned on too.
//
//Return the number of moments in which all turned on bulbs are blue.


//在任意一个位置，如果最大值==i+1,最小值为1,则说明所有灯都亮了

class Solution {
public:
	int numTimesAllBlue(vector<int>& light) {
		int n = light.size();
		int left_max = 0;
		int left_min = INT_MAX / 2;
		int rs = 0;
		for (int i = 0; i<n; i++) {
			left_max = max(left_max, light[i]);
			left_min = min(left_min, light[i]);
			if (left_min == 1 && left_max == i + 1)
				rs++;
		}
		return rs;
	}
};