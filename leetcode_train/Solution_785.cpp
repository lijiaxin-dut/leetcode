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

class Solution_785 {
public:
	bool isBipartite(vector<vector<int>>& graph) {

		int n = graph.size();
		vector<int>color(n, 0);
		for (int i = 0; i<n; i++) {
			if (color[i] != 0)
				continue;
			queue<int>Q;
			Q.push(i);
			color[i] = 1;
			while (!Q.empty()) {
				int size = Q.size();
				for (int i = 0; i<size; i++) {
					int t = Q.front();
					Q.pop();
					for (auto &one_n : graph[t]) {
						if (color[one_n] != -color[t])
							return false;
						if (color[one_n] == 0)
							Q.push(one_n);
						color[one_n] = -color[t];
					}
				}
			}
		}
		return true;


	}
};

