#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<set>
using namespace std;
//Given a list of airline tickets represented by pairs of departure and arrival airports[from, to], reconstruct the itinerary in order.All of the tickets belong to a man who departs from JFK.Thus, the itinerary must begin with JFK.
//
//Note:
//
//If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.For example, the itinerary["JFK", "LGA"] has a smaller lexical order than["JFK", "LGB"].
//All airports are represented by three capital letters(IATA code).
//You may assume all tickets form at least one valid itinerary.

//Ѱ��ŷ����·

//dfs�������еı�
//��¼ÿ���߳��ֵĴ�������

//�������ر�


class Solution_332
{
public:
	//�ڵݹ����ʱ������ǰ�ڵ���뵽route��
	//In Eulerian paths, there must exist a start node(which is JFK in this problem) and a end node.
	//	End node can be start node or another node.
	//	end node is start node iff all nodes has even degree.
	//	end node is another node iff there is another odd degree node and start node has an odd degree.
	vector<string> findItinerary_dfs(vector<vector<string>>& tickets) {
		for (auto ticket : tickets)
			targets[ticket[0]].insert(ticket[1]);
		visit("JFK");
		return vector<string>(route.rbegin(), route.rend());
	}
	map<string, multiset<string>> targets;
	vector<string> route;

	void visit(string airport) {
		while (targets[airport].size()) {
			string next = *targets[airport].begin();
			targets[airport].erase(targets[airport].begin());
			visit(next);
		}
		route.push_back(airport);
	}


	//dfs�������еı�
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		map<string, map<string, int>> m, vis;
		for (auto t : tickets)
			m[t[0]][t[1]]++;
		vector<string> res, cur;
		// �����ʼ��
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
		//û��ָ���ı�
		if (m.find(current_node) == m.end())
			return;
		for (auto &one_tic : m[current_node]) {
			string stop = one_tic.first;
			//��������еĻ�Ʊ���ù���
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