#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

//dp[i][j]表示[0,i)  [0,j)的编辑距离
//the minimum number of operations to convert word1[0..i) to word2[0..j).
//word1[i - 1] == word2[j - 1]->p[i][j] = dp[i - 1][j - 1]

//删除word1[i - 1]   
//execu
//exect   
//i j 指向最后一个元素，dp[i][j] = dp[i - 1][j] + 1

//替换word1[i - 1] by word2[j - 1]
//execu  
//exect   
//i j 指向最后一个元素，dp[i][j] = dp[i - 1][j-1] + 1

//添加
//exec   
//exect 
//i j 指向最后一个元素,c后面添加t,变为相同 dp[i][j] = dp[i][j-1] + 1


class Solution_72 {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();
		vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++)
			dp[i][0] = i;
		for (int j = 1; j <= n; j++)
			dp[0][j] = j;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
			}
		}
		return dp[m][n];


	}
};