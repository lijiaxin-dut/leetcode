#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
#include<map>
using namespace std;

//The demons had captured the princess(P) and imprisoned her in the bottom - right corner of a dungeon.The dungeon consists of M x N rooms laid out in a 2D grid.Our valiant knight(K) was initially positioned in the top - left room and must fight his way through the dungeon to rescue the princess.
//
//The knight has an initial health point represented by a positive integer.If at any point his health point drops to 0 or below, he dies immediately.
//
//Some of the rooms are guarded by demons, so the knight loses health(negative integers) upon entering these rooms; other rooms are either empty(0's) or contain magic orbs that increase the knight's health(positive integers).
//
//	In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


//�����½ǿ�ʼ�ݹ�
//dp[i][j]��ʾ��[i][j]��Ҫ������

class Solution_174 {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int m = dungeon.size();
		int n = dungeon[0].size();
		vector<vector<int>>dp(m, vector<int>(n, INT_MAX));
		dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);
		for (int i = m - 2; i >= 0; i--)
			dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
		for (int i = n - 2; i >= 0; i--)
			dp[m - 1][i] = max(1, dp[m - 1][i + 1] - dungeon[m - 1][i]);

		for (int i = m - 2; i >= 0; i--) {
			for (int j = n - 2; j >= 0; j--) {
				int dp_min = min(dp[i + 1][j], dp[i][j + 1]);
				dp[i][j] = max(1, dp_min - dungeon[i][j]);
			}
		}
		return dp[0][0];

	}
};