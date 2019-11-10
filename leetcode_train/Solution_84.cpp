#include<vector>
#include<algorithm>
#include<stack>

using namespace std;
//
//Given n non - negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

//找到每一个递减的位置，然后计算从开始位置到该位置的面积


//使用递增栈
//当存在降序时，就不断的从栈中弹出数据
//因为是递增栈，已经弹出的数据，跟当前弹出的数据，一定能构成长方形

//1，5，6，2
//当前元素是2
//先弹出6，面积是 6*（3-1-1）=6
//在弹出5，面积是 5*（3-1-0）=10



class Solution_84 {
public:

	//https ://www.geeksforgeeks.org/largest-rectangle-under-histogram/
	int largestRectangleArea_stack(vector<int>& heights) {
		int rs = 0;
		stack<int>st;
		heights.push_back(0);
		for (int i = 0; i<heights.size(); i++) {
			if (st.empty() || heights[st.top()] <= heights[i])
				st.push(i);
			else {
				//cur 为到i-1为止，最小的值

				int cur = st.top();
				st.pop();
				//如果栈为空，cur就是从开始为止的最小值，length=i即可
				int length = i;
				if (!st.empty())
					length = i - st.top() - 1;
				rs = max(rs, heights[cur] * length);
				--i;
			}
		}
		return rs;

	}

	int largestRectangleArea(vector<int>& heights) {
		int rs = 0;
		int n = heights.size();
		for (int i = 0; i<n; i++) {
			if (i + 1<n&&heights[i] <= heights[i + 1])
				continue;
			int min_val = heights[i];
			for (int j = i; j >= 0; j--) {
				min_val = min(min_val, heights[j]);
				rs = max(rs, min_val*(i - j + 1));
			}
		}
		return rs;

	}
};