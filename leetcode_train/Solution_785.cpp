#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<iterator>
#include<queue>
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;



//�ж�һ��ͼ�Ƿ��Ƕ���ͼ
//����̰��

// bfs Ⱦɫ��
//ÿһ��Ⱦ��ͬ����ɫ�����һ�㱻Ⱦɫ�ˣ��´��ٴ���������㣬�뵱ǰ���ڵ���ɫ��ͬ��˵�����Ƕ���ͼ

//ͼ���ܲ�����ͨͼ��������Ҫ�Զ�������BFS

class Solution {
public:
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int>mark(n, 0);
		for (int j = 0; j<n; j++) {
			if (mark[j] != 0)
				continue;
			queue<int>q;
			q.push(j);
			mark[j] = 1;
			while (!q.empty()) {
				int size = q.size();
				for (int i = 0; i < size; i++) {
					int cur_node = q.front();
					q.pop();
					for (auto &neighbor : graph[cur_node]) {
						if (mark[neighbor] == 0) {
							q.push(neighbor);
							mark[neighbor] = -mark[cur_node];
						}
						else if (mark[cur_node] * mark[neighbor] == 1) {
							return false;
						}
					}
				}

			}
		}
		return true;
	}
};
