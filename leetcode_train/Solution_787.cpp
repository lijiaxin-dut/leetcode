#include<vector>
#include<algorithm>
using namespace std;


//1.dfs加剪枝
//2.  dp[i][j]表示最多经过i步到达j的代价
//    对于所有可能的边数，松弛所有的边

class Solution_787 {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

		vector<vector<int>> dp(K + 2, vector<int>(n, 1e9));
		for (int i = 0; i <= K + 1; i++)
			dp[i][src] = 0;
		for (int i = 1; i <= K + 1; i++) {
			for (auto &one_flight : flights) {
				int s = one_flight[0];
				int e = one_flight[1];
				int p = one_flight[2];
				dp[i][e] = min(dp[i][e], dp[i - 1][s] + p);

			}
		}
		return (dp[K + 1][dst] >= 1e9) ? -1 : dp[K + 1][dst];
	}

};