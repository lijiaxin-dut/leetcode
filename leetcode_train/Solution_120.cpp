#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given a triangle, find the minimum path sum from top to bottom.Each step you may move to 
////adjacent numbers on the row below.
//
//For example, given the following triangle
//
//[
//	[2],
//	[3, 4],
//	[6, 5, 7],
//	[4, 1, 8, 3]
//]
//The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).


//dp[j]=triangle[i][j]=min(dp[j-1],dp[j])
//每次用一行临时数组存储上一行的结果

class Solution_120 {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty())
			return 0;
		int n = triangle.size();
		vector<int>dp(n, 0);
		dp[0] = triangle[0][0];
		vector<int>temp = dp;
		for (int i = 1; i<n; i++) {
			dp[0] = triangle[i][0] + temp[0];
			int current_line_size = triangle[i].size();
			for (int j = 1; j<current_line_size - 1; j++) {
				dp[j] = triangle[i][j] + min(temp[j], temp[j - 1]);
			}
			dp[current_line_size - 1] = triangle[i][current_line_size - 1] + temp[current_line_size - 2];
			temp = dp;
		}
		int rs = INT_MAX;
		for (const auto i : temp) {
			rs = min(rs, i);
		}
		return rs;
	}
};