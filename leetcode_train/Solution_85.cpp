#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
//Example:
//
//Input:
//[
//	["1", "0", "1", "0", "0"],
//	["1", "0", "1", "1", "1"],
//	["1", "1", "1", "1", "1"],
//	["1", "0", "0", "1", "0"]
//]
//Output: 6


//二维矩阵每一层向上都可以看做一个直方图，输入矩阵有多少行，就可以形成多少个直方图，
//对每个直方图都调用 Largest Rectangle in Histogram 中的方法，
//就可以得到最大的矩形面积。




class Solution_85 {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (m == 0)
			return 0;
		int n = matrix[0].size();
		vector<int>heights(n, 0);
		int rs = 0;
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (matrix[i][j] == '1')
					heights[j]++;
				else
					heights[j] = 0;
			}
			rs = max(rs, largestRectangleArea(heights));
		}
		return rs;
	}
	int largestRectangleArea(vector<int>&heights) {
		int rs = 0;
		stack<int>st;
		heights.push_back(0);
		for (int i = 0; i<heights.size(); i++) {
			if (st.empty() || heights[st.top()] <= heights[i])
				st.push(i);
			else {
				int cur = st.top();
				st.pop();
				int length = i;
				if (!st.empty())
					length = i - st.top() - 1;
				rs = max(rs, heights[cur] * length);
				i--;
			}
		}
		return rs;
	}
};