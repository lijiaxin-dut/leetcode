#include<vector>

using namespace std;
//You have N gardens, labelled 1 to N.In each garden, you want to plant one of 4 types of flowers.
//
//paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.
//
//Also, there is no garden that has more than 3 paths coming into or leaving it.
//
//Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.
//
//Return any such a choice as an array answer, where answer[i] is the type of flower planted in the(i + 1) - th garden.The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.

//贪心，逐个点染色，遍历邻居节点，标记未使用的颜色

class Solution_1042 {
public:
	vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
		vector<vector<int>>graph(N);
		for (auto &one_path : paths) {
			graph[one_path[1] - 1].push_back(one_path[0] - 1);
			graph[one_path[0] - 1].push_back(one_path[1] - 1);
		}
		vector<int>res(N, 0);

		for (int i = 0; i<N; i++) {
			vector<int>used(5, false);
			for (auto &j : graph[i]) {
				used[res[j]] = true;
			}
			for (int j = 1; j <= 4; j++)
				if (used[j] == false)
					res[i] = j;
		}
		return res;



	}
};