#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

//dp[i][j]��ʾ[0,i)  [0,j)�ı༭����

//word1[i - 1] == word2[j - 1]->p[i][j] = dp[i - 1][j - 1]

//ɾ��word1[i - 1]   
//execu
//exect   
//i j ָ�����һ��Ԫ�أ�dp[i][j] = dp[i - 1][j] + 1

//�滻word1[i - 1] by word2[j - 1]
//execu  
//exect   
//i j ָ�����һ��Ԫ�أ�dp[i][j] = dp[i - 1][j-1] + 1

//���
//exec   
//exect 
//i j ָ�����һ��Ԫ��,c�������t,��Ϊ��ͬ dp[i][j] = dp[i][j-1] + 1


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