#include<vector>
#include<queue>
using namespace std;


//Given a set of N people(numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
//
//Each person may dislike some other people, and they should not go into the same group.
//
//Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
//
//Return true if and only if it is possible to split everyone into two groups in this way.
//
//
//
//Example 1:
//
//Input: N = 4, dislikes = [[1, 2], [1, 3], [2, 4]]
//	Output : true
//	Explanation : group1[1, 4], group2[2, 3]


//bfs 染色法
//是否构成二部图



class Solution_886 {
public:
	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		vector<vector<int>>graph(N + 1);
		for (auto &one_edge : dislikes) {
			graph[one_edge[0]].push_back(one_edge[1]);
			graph[one_edge[1]].push_back(one_edge[0]);
		}
		vector<int>color(N + 1, 0);
		for (int i = 1; i <= N; i++) {
			if (color[i] == 0) {
				if (bfs(i, N, graph, color) == false)
					return false;
			}
		}
		return true;
	}

	bool bfs(int current_node, int N, vector<vector<int>>&graph, vector<int>&color) {
		queue<int>q;
		q.push(current_node);
		color[current_node] = 1;
		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			for (auto &out_node : graph[t]) {
				//还没有被染色
				if (color[out_node] == 0) {
					color[out_node] = -color[t];
					q.push(out_node);
				}
				//已经被染过色
				else if (color[out_node] != -color[t])
					return false;
			}
		}
		return true;
	}
};