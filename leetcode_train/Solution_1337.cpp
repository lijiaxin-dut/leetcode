#include<queue>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		auto c = [](const pair<int, int>&a,const pair<int, int>&b) {
			return a.first > b.first || (a.first == b.first&&a.second > b.second);
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(c)>pq(c);
		int m = mat.size();
		int n = mat[0].size(); 
		for (int i = 0; i<m; i++) {
			int sum = 0;
			for (int j = 0; j<n; j++) {
				if (mat[i][j] == 0)
					break;
				sum++;
			}
			pq.push(make_pair(sum, i));
		}
		vector<int>rs;
		while (k>0) {
			rs.push_back(pq.top().second);
			pq.pop();
		}
		return rs;
	}
};

