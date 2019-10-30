#include<unordered_map>
#include<vector>

using namespace std;

//Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number(floating point number).Given some queries, return the answers.If the answer does not exist, return -1.0.
//
//Example:
//Given a / b = 2.0, b / c = 3.0.
//queries are : a / c = ? , b / a = ? , a / e = ? , a / a = ? , x / x = ? .
//return[6.0, 0.5, -1.0, 1.0, -1.0].

//把问题建模为图
//一个等式对应两条边  a/b=2   b/a=0.5
//dfs即可

class Solution_399 {
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		unordered_map<string, vector<string>>graph;
		unordered_map<string, unordered_map<string, double>>value;
		unordered_map<string, bool>mark;
		for (int i = 0; i<equations.size(); i++) {
			graph[equations[i][0]].push_back(equations[i][1]);
			value[equations[i][0]][equations[i][1]] = values[i];
			graph[equations[i][1]].push_back(equations[i][0]);
			value[equations[i][1]][equations[i][0]] = 1.0 / values[i];
			mark[equations[i][0]] = false;
			mark[equations[i][1]] = false;
		}
		int n = queries.size();
		vector<double>rs(n, 1);
		for (int i = 0; i<n; i++) {
			if (mark.find(queries[i][0]) != mark.end()) {
				bool find = false;
				vector<string>path;
				mark[queries[i][0]] = true;
				path.push_back(queries[i][0]);
				dfs(value, rs[i], find, path, queries[i][1], queries[i][0], graph, mark);
				path.pop_back();
				mark[queries[i][0]] = false;
				if (find == false)
					rs[i] = -1;
			}
			else
				rs[i] = -1;
		}
		return rs;


	}
	void dfs(unordered_map<string, unordered_map<string, double>>&values, double &rs, bool &find, vector<string>&path, string &end_node, string &current_node, unordered_map<string, vector<string>>&graph, unordered_map<string, bool>&mark) {
		if (find == true)
			return;
		if (current_node == end_node) {
			find = true;
			for (int i = 0; i<int(path.size()) - 1; i++) {
				rs *= values[path[i]][path[i + 1]];
			}
			return;
		}

		for (auto &out : graph[current_node]) {
			if (mark[out] == false) {
				path.push_back(out);
				mark[out] = true;
				dfs(values, rs, find, path, end_node, out, graph, mark);
				path.pop_back();
				mark[out] = false;
			}
		}

	}

};

//int main() {
//	Solution_399 s;
//	vector<vector<string>>equations{ { "a","b" },{ "c","b" } };
//	vector<double> values{ 2.0,3.0 };
//	vector<vector<string>>q{ { "a","c" },{ "b","a" } };
//	s.calcEquation(equations, values, q);
//}