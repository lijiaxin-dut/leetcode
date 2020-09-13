#include<vector>
#include<string>

using namespace std;
//Given an array equations of strings that represent relationships between variables, each string equations[i] has length 4 and takes one of two different forms : "a==b" or "a!=b".Here, a and b are lowercase letters(not necessarily different) that represent one - letter variable names.
//
//Return true if and only if it is possible to assign integers to variable names so as to satisfy all the given equations.
//
//
//
//Example 1:
//
//Input: ["a==b", "b!=a"]
//	Output : false
//	Explanation : If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.There is no way to assign the variables to satisfy both equations.
//

//1.dfs  
//所有等式构造一个图


//2.并查集


class Solution_990 {
public:
	bool equationsPossible(vector<string>& equations) {
		vector<vector<char>>graph(256);
		vector<string>not_equal;
		for (auto &one_q : equations) {
			if (one_q[1] == '!')
				not_equal.push_back(one_q);
			else {
				graph[one_q[0]].push_back(one_q[3]);
				graph[one_q[3]].push_back(one_q[0]);
			}
		}
		for (auto &one_node_equal : not_equal) {
			char s = one_node_equal[0];
			char e = one_node_equal[3];
			if (s == e)
				return false;
			vector<int>mark(26, 0);
			mark[s - 'a'] = 1;
			bool is_connect = false;
			dfs(graph, mark, s, e, is_connect);
			if (is_connect == true)
				return false;
		}
		return true;
	}
	void dfs(vector<vector<char>>&graph, vector<int>&mark, char cur, char dst, bool &is_connect) {
		if (is_connect == true)
			return;
		if (cur == dst) {
			is_connect = true;
			return;
		}
		for (auto &out_node : graph[cur]) {
			if (mark[out_node - 'a'] == 0) {
				mark[out_node - 'a'] = 1;
				dfs(graph, mark, out_node, dst, is_connect);
			}
		}
	}
};

class UF {
public:
	vector<int>id;
	UF() {
		id.resize(26);
		for (int i = 0; i<26; i++) {
			id[i] = i;
		}
	}

	int find(int p) {
		int root = p;
		while (root != id[root]) {
			root = id[root];
		}
		while (id[p] != root) {
			int temp = id[p];
			id[p] = root;
			p = temp;
		}
		return root;
	}

	void connect(int p, int q) {
		int p_root = find(p);
		int q_root = find(q);
		if (p_root == q_root)
			return;
		id[p_root] = q_root;
	}

	bool connected(int p, int q) {
		int p_root = find(p);
		int q_root = find(q);
		return p_root == q_root;
	}

};

class Solution_uf {
public:
	bool equationsPossible(vector<string>& equations) {
		UF uf;
		for (auto &one_equ : equations) {
			int a = one_equ[0] - 'a';
			int b = one_equ[3] - 'a';
			if (one_equ[1] == '=')
				uf.connect(a, b);
		}
		for (auto &one_equ : equations) {
			int a = one_equ[0] - 'a';
			int b = one_equ[3] - 'a';
			if (one_equ[1] == '!') {
				if (uf.connected(a, b) == true)
					return false;
			}
		}
		return true;

	}
};