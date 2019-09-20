#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;


class Solution_661 {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		if (M.empty() || M[0].empty())
			return{};
		int m = M.size();
		int n = M[0].size();
		vector<vector<int>>rs(m, vector<int>(n, 0));
		vector<int>x{ -1 ,-1,-1, 0,0, 1, 1,1 };
		vector<int>y{ -1 , 0, 1,-1,1,-1, 0,1 };
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				int one_rs = M[i][j];
				int size = 1;
				for (int k = 0; k<8; k++) {
					int new_x = i + x[k];
					int new_y = j + y[k];
					if (new_x<0 || new_x >= m || new_y<0 || new_y >= n)
						continue;
					one_rs += M[new_x][new_y];
					size++;
				}
				rs[i][j] = one_rs / size;
			}
		}
		return rs;
	}
};

//int main() {
//	Solution_661 s;
//	vector<vector<int>>M{ {2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16} };
//	s.imageSmoother(M);
//}