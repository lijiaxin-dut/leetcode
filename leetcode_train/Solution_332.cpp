#include<string>
#include<sstream>
#include<vector>
#include<map>
using namespace std;


//dfs遍历所有的边
//记录每条边出现的次数即可

//允许有重边


class Solution_332
{
public:
	//dfs遍历所有的边
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		map<string, map<string, int>> m, vis;
		for (auto t : tickets)
			m[t[0]][t[1]]++;
		vector<string> res, cur;
		// 添加起始点
		cur.push_back("JFK");
		string current_node = "JFK";
		dfs(current_node, m, vis, cur, tickets.size() + 1, res);
		return res;
	}
	void dfs(string &current_node, map<string, map<string, int>>& m, map<string, map<string, int>>& vis, vector<string>& cur, int n, vector<string>& res) {
		if (res.size() == n)
			return;
		if (cur.size() == n) {
			res = cur;
			return;
		}
		//没有指出的边
		if (m.find(current_node) == m.end())
			return;
		for (auto &one_tic : m[current_node]) {
			string stop = one_tic.first;
			//这个边所有的机票都用过了
			if (vis[current_node][stop] == one_tic.second)
				continue;
			vis[current_node][stop]++;
			cur.push_back(stop);
			dfs(stop, m, vis, cur, n, res);
			cur.pop_back();
			vis[current_node][stop]--;

		}





	}

};