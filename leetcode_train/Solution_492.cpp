#include<vector>

using namespace std;
//
//For a web developer, it is very important to know how to design a web page's size. So, given a specific rectangular web page’s area, your job by now is to design a rectangular web page, whose length L and width W satisfy the following requirements:
//
//1. The area of the rectangular web page you designed must equal to the given target area.
//
//2. The width W should not be larger than the length L, which means L >= W.
//
//3. The difference between length L and width W should be as small as possible.

//从1开始遍历即可

class Solution_492 {
	bool is_prime(int n) {
		for (int i = 2; i*i <= n; i++) {
			if (n%i == 0)
				return false;
		}
		return true;

	}
public:
	vector<int> constructRectangle(int area) {
		if (is_prime(area)) {
			return{ area,1 };
		}
		int L;
		int W;
		int diff = INT_MAX;
		for (int cur_w = 1; cur_w <= area; cur_w++) {
			int cur_l = area / cur_w;
			if (cur_l*cur_w != area)
				continue;
			if (cur_l<cur_w)
				break;
			if (cur_l - cur_w<diff) {
				L = cur_l;
				W = cur_w;
			}
		}
		return{ L,W };

	}
};