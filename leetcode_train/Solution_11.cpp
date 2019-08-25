#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;


//Description
//Given n non - negative integers a1, a2, ..., an, where each represents a point at coordinate(i, ai).
//n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and (i, 0).
//Find two lines, which together with x - axis forms a container, such that the container contains the most water.


class Solution_11 {
public:
	int maxArea(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int max_area = 0;
		while (left<right) {
			int current_area = min(height[left], height[right])*(right - left);
			max_area = max(max_area, current_area);
			if (height[left]<height[right])
				left++;
			else
				right--;
		}
		return max_area;
	}
};
//int main() {
//	Solution_11 s;
//	cout<<s.maxArea(vector<int>{ 1,8,6,2,5,4,8,3,7 });
//}