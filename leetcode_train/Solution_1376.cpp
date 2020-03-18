#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

//
//A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company has is the one with headID.
//
//Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i - th employee, manager[headID] = -1. Also it's guaranteed that the subordination relationships have a tree structure.
//
//The head of the company wants to inform all the employees of the company of an urgent piece of news.He will inform his direct subordinates and they will inform their subordinates and so on until all employees know about the urgent news.
//
//The i - th employee needs informTime[i] minutes to inform all of his direct subordinates(i.e After informTime[i] minutes, all his direct subordinates can start spreading the news).
//
//Return the number of minutes needed to inform all the employees about the urgent news.


//bfs, 记录到当前位置的通知时间
//返回一个最大值

class Solution {
public:
	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		unordered_map<int, vector<int>>graph;
		for (int i = 0; i<manager.size(); i++) {
			int cur_em_id = i;
			int cur_mamage_id = manager[i];
			if (cur_mamage_id != -1) {
				graph[cur_mamage_id].push_back(cur_em_id);
			}
		}
		int rs = 0;
		queue<pair<int, int>>q;
		q.push(make_pair(headID, informTime[headID]));
		while (!q.empty()) {
			int cur_size = q.size();
			int max_time = 0;
			for (int i = 0; i<cur_size; i++) {
				int cur_info = q.front().first;
				int cur_time = q.front().second;
				rs = max(rs, cur_time);
				q.pop();
				max_time = max(max_time, informTime[cur_info]);
				for (auto &next_level : graph[cur_info]) {
					q.push(make_pair(next_level, cur_time + informTime[next_level]));
				}
			}

		}
		return rs;
	}
};