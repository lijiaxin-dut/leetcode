#include<vector>

using namespace std;


//In this problem, a tree is an undirected graph that is connected and has no cycles.
//
//The given input is a graph that started as a tree with N nodes(with distinct values 1, 2, ..., N), with one additional edge added.The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.
//
//The resulting graph is given as a 2D - array of edges.Each element of edges is a pair[u, v] with u < v, that represents an undirected edge connecting nodes u and v.
//
//	Return an edge that can be removed so that the resulting graph is a tree of N nodes.If there are multiple answers, return the answer that occurs last in the given 2D - array.The answer edge[u, v] should be in the same format, with u < v.
//
//	Example 1:
//Input: [[1, 2], [1, 3], [2, 3]]
//	Output : [2, 3]
//	Explanation : The given undirected graph will be like this :
//	1
//	/ \
//	2 - 3


//并查集，按顺序添加边，如果一条边的两个终点已经联通，返回这条边


class Solution_684 {
	class UF {
	public:
		int count;
		vector<int>id;
		UF(int n) {
			count = n;
			id.resize(n);
			for (int i = 0; i<n; i++) {
				id[i] = i;
			}
		}
		int find(int p) {
			int root = p;
			while (root != id[root])
				root = id[root];
			while (p != id[root]) {
				int t = id[p];
				id[p] = root;
				p = t;
			}
			return root;
		}
		bool connect(int p, int q) {
			int p_root = find(p);
			int q_root = find(q);
			if (p_root == q_root)
				return false;
			id[p_root] = q_root;
			count--;
			return true;
		}
	};
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int n = edges.size();
		UF uf(n + 1);
		for (auto &one_edge : edges) {
			if (uf.connect(one_edge[0], one_edge[1]) == false)
				return one_edge;
		}
		return{};

	}

};