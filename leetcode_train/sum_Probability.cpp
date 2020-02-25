#include<vector>
#include<map>;
using namespace std;
//
//把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
//
//
//
//你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

//1.dfs  生成所有可能的sum,然后计算频率

class Solution {
public:
	vector<double> twoSum_dp(int n) {
		//dp[i][j]表示前i个骰子求和为j的个数
		vector<vector<int>> dp(n, vector<int>(6 * n + 1, 0));
		int count = pow(6, n);
		for (int j = 1; j <= 6; j++)
			dp[0][j] = 1;
		for (int i = 1; i<n; i++) {
			for (int j = i + 1; j <= 6 * (i + 1); j++) {
				for (int k = 1; k <= 6; k++) {
					if (j>k) {
						dp[i][j] += dp[i - 1][j - k];
					}
				}
			}
		}
		vector<double> ans;
		for (int j = n; j <= 6 * n; ++j)
			ans.push_back(double(dp[n - 1][j]) / count);
		return ans;

	}
	vector<double> twoSum(int n) {
		vector<int>all_sum = help(n);
		int total_size = all_sum.size();
		map<int, int>count;
		for (auto &one_sum : all_sum)
			count[one_sum]++;
		vector<double>rs;
		for (auto &one_sum : count) {
			rs.push_back(one_sum.second / double(total_size));
		}
		return rs;
	}
	vector<int>help(int n) {
		if (n == 1)
			return{ 1,2,3,4,5,6 };
		vector<int>cur{ 1,2,3,4,5,6 };
		vector<int>next_iterator = help(n - 1);
		vector<int>rs;
		for (int i = 0; i<cur.size(); i++) {
			for (int j = 0; j<next_iterator.size(); j++) {
				rs.push_back(cur[i] + next_iterator[j]);
			}
		}
		return rs;
	}
};