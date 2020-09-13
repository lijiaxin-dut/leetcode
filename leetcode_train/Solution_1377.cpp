#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<queue>
using namespace std;

//
//公司里有 n 名员工，每个员工的 ID 都是独一无二的，编号从 0 到 n - 1。公司的总负责人通过 headID 进行标识。
//
//在 manager 数组中，每个员工都有一个直属负责人，其中 manager[i] 是第 i 名员工的直属负责人。对于总负责人，manager[headID] = -1。题目保证从属关系可以用树结构显示。
//
//公司总负责人想要向公司所有员工通告一条紧急消息。他将会首先通知他的直属下属们，然后由这些下属通知他们的下属，直到所有的员工都得知这条紧急消息。
//
//第 i 名员工需要 informTime[i] 分钟来通知它的所有直属下属（也就是说在 informTime[i] 分钟后，他的所有直属下属都可以开始传播这一消息）。
//
//返回通知所有员工这一紧急消息所需要的 分钟数 。


//SPFA找最短路

struct edge {
	int cost;
	int end;
	edge(int c, int e) :cost(c), end(e) {}
};
class Solution {
	int spfa(const vector<vector<edge>>&graph, int s, int n) {
		vector<int>distTo(n, INT_MAX);
		distTo[s] = 0;
		queue<int>q;
		q.push(s);
		vector<bool>onQueue(n, false);
		while (!q.empty()) {
			int cur_node = q.front();
			q.pop();
			onQueue[cur_node] = false;
			for (auto &one_nei : graph[cur_node]) {
				int end = one_nei.end;
				int cost = one_nei.cost;
				if (distTo[end]>distTo[cur_node] + cost) {
					distTo[end] = distTo[cur_node] + cost;
					if (onQueue[end] == false) {
						onQueue[end] = true;
						q.push(end);
					}
				}
			}
		}
		return *max_element(distTo.begin(), distTo.end());
	}
public:
	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		vector<vector<edge>>graph(n);
		for (int i = 0; i<n; i++) {
			int s = manager[i];
			int e = i;
			int c = informTime[i];
			if (i != headID)
				graph[s].push_back(edge(c, e));
		}
		return spfa(graph, headID, n) + informTime[headID];
	}
};