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
		int rs = 0;
		int max_val = 0;
		int min_val = INT_MAX;
		for (int i = 0; i<light.size(); i++) {
			max_val = max(max_val, light[i]);
			min_val = min(min_val, light[i]);
			if (min_val == 1 && max_val == i + 1) {
				rs++;
			}
		}
		return rs;
	}
};