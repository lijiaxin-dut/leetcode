#include<vector>
#include<queue>
#include<memory>

using namespace std;


//In a given 2D binary array A, there are two islands.  (An island is a 4 - directionally connected group of 1s not connected to any other 1s.)
//
//Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.
//
//Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)
//
//
//
//Example 1:
//
//Input: [[0, 1], [1, 0]]
//	Output : 1
//	Example 2 :
//
//	Input : [[0, 1, 0], [0, 0, 0], [0, 0, 1]]
//	Output : 2
//	Example 3 :
//
//	Input : [[1, 1, 1, 1, 1], [1, 0, 0, 0, 1], [1, 0, 1, 0, 1], [1, 0, 0, 0, 1], [1, 1, 1, 1, 1]]
//	Output : 1


//多源BFS
//找到一个1所在的位置，进行DFS，然后从所有找到的位置进行BFS
//lc 542
//不断的向外扩展

class Solution {
	vector<int>xx{ 0,0,1,-1 };
	vector<int>yy{ 1,-1,0,0 };
public:
	int shortestBridge(vector<vector<int>>& A) {
		int n = A.size();
		queue<pair<int, int>>q;
		bool found = false;
		for (int i = 0; i<n&&found == false; i++) {
			for (int j = 0; j<n&&found == false; j++) {
				if (A[i][j] == 1) {
					A[i][j] = 2;
					q.push(make_pair(i, j));
					dfs(q, n, A, i, j);
					found = true;
				}
			}
		}
		int step = 0;
		while (!q.empty()) {
			int level_size = 0;
			for (int i = 0; i<level_size; i++) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int i = 0; i<4; i++) {
					int new_x = x + xx[i];
					int new_y = y + yy[i];
					if (new_x<0 || new_x >= n || new_y<0 || new_y >= n || A[new_x][new_y] == 2)
						continue;
					if (A[new_x][new_y] == 1)
						return step;
					A[new_x][new_y] = 2;
					q.push(make_pair(new_x, new_y));
				}
			}
			step++;
		}
		return step;
	}
	void dfs(queue<pair<int, int>>&q, int n, vector<vector<int>>& A, int x, int y) {
		for (int i = 0; i<4; i++) {
			int new_x = x + xx[i];
			int new_y = y + yy[i];
			if (new_x<0 || new_x >= n || new_y<0 || new_y >= n || A[new_x][new_y] == 0 || A[new_x][new_y] == 2)
				continue;
			A[new_x][new_y] = 2;
			q.push(make_pair(new_x, new_y));
			dfs(q, n, A, new_x, new_y);
		}

	}

};

