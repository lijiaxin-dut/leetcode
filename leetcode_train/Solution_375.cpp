#include<vector>
#include<algorithm>
using namespace std;

//We are playing the Guess Game.The game is as follows :
//
//I pick a number from 1 to n.You have to guess which number I picked.
//
//Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
//
//However, when you guess a particular number x, and you guess wrong, you pay $x.You win the game when you guess the number I picked.
//
//Example:
//
//n = 10, I pick 8.
//
//First round : You guess 5, I tell you that it's higher. You pay $5.
//Second round : You guess 7, I tell you that it's higher. You pay $7.
//Third round : You guess 9, I tell you that it's lower. You pay $9.
//
//Game over. 8 is the number I picked.
//
//You end up paying $5 + $7 + $9 = $21.
//Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

//minmax问题
//dp[i][j]表示i->j的最小值

//For each number x in range[i~j]
//假设猜x不是目标是，需要在左右两侧继续搜索，因为不知道目标在哪一侧，返回左和右的最大值
//we do: result_when_pick_x = x + max{ DP([i~x - 1]), DP([x + 1, j]) }
//--> // the max means whenever you choose a number, the feedback is always bad and therefore leads you to a worse branch.
//then we get DP([i~j]) = min{ xi, ... ,xj }
//--> // this min makes sure that you are minimizing your cost.

class Solution_375 {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
		return dfs(dp, 1, n);
	}
	int dfs(vector<vector<int>>&dp, int s, int e) {
		if (s >= e)
			return 0;
		if (dp[s][e] != 0)
			return dp[s][e];
		int rs = INT_MAX;
		for (int x = s; x <= e; x++) {
			int m = x + max(dfs(dp, s, x - 1), dfs(dp, x + 1, e));
			rs = min(rs, m);
		}
		dp[s][e] = rs;
		return rs;
	}
};