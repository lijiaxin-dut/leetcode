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