#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
//Input: 5
//	Output :
//	[
//		[1],
//		[1, 1],
//		[1, 2, 1],
//		[1, 3, 3, 1],
//		[1, 4, 6, 4, 1]
//	]

//根据规律输出
//一行一行的产生
//第0列和最后一列全是1
//rs[i][j]=rs[i-1][j]+rs[i-1][j-1]
class Solution_118 {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>>rs;
		for (int i = 0; i<numRows; i++) {
			vector<int>one_row;
			for (int j = 0; j <= i; j++) {
				if (i == 0 || j == 0 || j == i) {
					one_row.push_back(1);
				}
				else {
					one_row.push_back(rs[i - 1][j] + rs[i - 1][j - 1]);
				}
			}
			rs.push_back(one_row);
		}
		return rs;
	}
};