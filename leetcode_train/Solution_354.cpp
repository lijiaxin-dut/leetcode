#include<vector>
#include<algorithm>


//You have a number of envelopes with widths and heights given as a pair of integers(w, h).One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
//
//What is the maximum number of envelopes can you Russian doll ? (put one inside other)
//
//Note :
//	Rotation is not allowed.
//
//	Example :
//
//	Input : [[5, 4], [6, 4], [6, 7], [2, 3]]
//	Output : 3
//	Explanation : The maximum number of envelopes you can Russian doll is 3 ([2, 3] = >[5, 4] = >[6, 7]).

//dp
//LIS

using namespace std;

class Solution_354 {
public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end(), [](vector<int>a, vector<int>b) {return a[0] * a[1]<b[0] * b[1]; });
		int n = envelopes.size();
		if (n == 0)
			return 0;
		vector<int>dp(n, 1);
		dp[0] = 1;
		int rs = 1;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<i; j++) {
				if (envelopes[j][0]<envelopes[i][0] && envelopes[j][1]<envelopes[i][1]) {
					dp[i] = max(dp[i], dp[j] + 1);
					rs = max(rs, dp[i]);
				}
			}

		}
		return rs;

	}
};

