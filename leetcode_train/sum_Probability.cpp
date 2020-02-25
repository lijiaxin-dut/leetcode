#include<vector>
#include<map>;
using namespace std;
//
//��n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs������n����ӡ��s�����п��ܵ�ֵ���ֵĸ��ʡ�
//
//
//
//����Ҫ��һ�����������鷵�ش𰸣����е� i ��Ԫ�ش����� n ���������������ĵ��������е� i С���Ǹ��ĸ��ʡ�

//1.dfs  �������п��ܵ�sum,Ȼ�����Ƶ��

class Solution {
public:
	vector<double> twoSum_dp(int n) {
		//dp[i][j]��ʾǰi���������Ϊj�ĸ���
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