#include<vector>
using namespace std;

//给出一个函数  f(x, y) 和一个目标结果 z，请你计算方程 f(x, y) == z 所有可能的正整数 数对 x 和 y。
//
//给定函数是严格单调的，也就是说：
//
//f(x, y) < f(x + 1, y)
//	f(x, y) < f(x, y + 1)
//

//在 1 <= x, y <= 1000 的前提下

class CustomFunction {
public:
	// Returns f(x, y) for any given positive integers x and y.
		// Note that f(x, y) is increasing with respect to both x and y.
		// i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
	int f(int x, int y);

};

class Solution {
public:
	vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
		vector<vector<int>>ans;
		for (int x = 1; x <= 1000; x++) {
			int left = 1;
			int right = 1000;
			while (left <= right) {
				int mid = left + (right - left) / 2;
				int rs = customfunction.f(x, mid);
				if (rs == z) {
					ans.push_back({ x,mid });
					break;
				}
				else if (rs>z) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
		}
		return ans;
	}
};