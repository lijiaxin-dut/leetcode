#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<iterator>
#include<queue>
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;



//判断一个图是否是二部图
//不能贪心

// bfs 染色法
//每一层染不同的颜色，如果一点被染色了，下次再次遇见这个点，与当前父节点颜色相同，说明不是二部图

//图可能不是连通图，可能需要对多个点进行BFS

class Solution {
public:
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int>mark(n, 0);
		for (int j = 0; j<n; j++) {
			if (mark[j] != 0)
				continue;
			queue<int>q;
			q.push(j);
			mark[j] = 1;
			while (!q.empty()) {
				int size = q.size();
				for (int i = 0; i < size; i++) {
					int cur_node = q.front();
					q.pop();
					for (auto &neighbor : graph[cur_node]) {
						if (mark[neighbor] == 0) {
							q.push(neighbor);
							mark[neighbor] = -mark[cur_node];
						}
						else if (mark[cur_node] * mark[neighbor] == 1) {
							return false;
						}
					}
				}

			}
		}
		return true;
	}
};
