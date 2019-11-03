#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<iterator>
#include<queue>
using namespace std;


//There are N network nodes, labelled 1 to N.
//
//Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.
//
//Now, we send a signal from a certain node K.How long will it take for all nodes to receive the signal ? If it is impossible, return -1.

//从所有的最短路径中挑一个最长的

//spfa找最短路

class Solution_743 {
	struct edge {
		int start;
		int end;
		int cost;
		edge(int s, int e, int c) :start(s), end(e), cost(c) {}
	};
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {

		vector<vector<edge>>matrix(N + 1);
		for (auto &one_edge : times) {
			matrix[one_edge[0]].emplace_back(one_edge[0], one_edge[1], one_edge[2]);
		}
		return spfa(matrix, N, K);
	}
	int spfa(vector<vector<edge>>&matrix, int N, int K) {
		vector<bool>Onqueue(N + 1);
		queue<int>Q;
		vector<int>distTo(N + 1, INT_MAX);
		Onqueue[K] = true;
		distTo[K] = 0;
		Q.push(K);
		while (!Q.empty()) {
			int t = Q.front();
			Q.pop();
			Onqueue[t] = false;
			for (auto &one_edge : matrix[t]) {
				int w = one_edge.end;
				if (distTo[t] + one_edge.cost<distTo[w]) {
					distTo[w] = distTo[t] + one_edge.cost;
					if (Onqueue[w] == false) {
						Onqueue[w] = true;
						Q.push(w);

					}
				}
			}
		}
		int max_length = 0;
		for (int i = 1; i <= N; i++) {
			max_length = max(distTo[i], max_length);
		}
		return max_length == INT_MAX ? -1 : max_length;

	}
};