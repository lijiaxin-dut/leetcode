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

class Solution_785 {
public:
	bool isBipartite(vector<vector<int>>& graph) {

		int n = graph.size();
		vector<int>color(n, 0);
		for (int i = 0; i<n; i++) {
			if (color[i] != 0)
				continue;
			queue<int>Q;
			Q.push(i);
			color[i] = 1;
			while (!Q.empty()) {
				int size = Q.size();
				for (int i = 0; i<size; i++) {
					int t = Q.front();
					Q.pop();
					for (auto &one_n : graph[t]) {
						if (color[one_n] != -color[t])
							return false;
						if (color[one_n] == 0)
							Q.push(one_n);
						color[one_n] = -color[t];
					}
				}
			}
		}
		return true;


	}
};

