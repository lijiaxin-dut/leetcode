#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<queue>
using namespace std;

//
//��˾���� n ��Ա����ÿ��Ա���� ID ���Ƕ�һ�޶��ģ���Ŵ� 0 �� n - 1����˾���ܸ�����ͨ�� headID ���б�ʶ��
//
//�� manager �����У�ÿ��Ա������һ��ֱ�������ˣ����� manager[i] �ǵ� i ��Ա����ֱ�������ˡ������ܸ����ˣ�manager[headID] = -1����Ŀ��֤������ϵ���������ṹ��ʾ��
//
//��˾�ܸ�������Ҫ��˾����Ա��ͨ��һ��������Ϣ������������֪ͨ����ֱ�������ǣ�Ȼ������Щ����֪ͨ���ǵ�������ֱ�����е�Ա������֪����������Ϣ��
//
//�� i ��Ա����Ҫ informTime[i] ������֪ͨ��������ֱ��������Ҳ����˵�� informTime[i] ���Ӻ���������ֱ�����������Կ�ʼ������һ��Ϣ����
//
//����֪ͨ����Ա����һ������Ϣ����Ҫ�� ������ ��


//SPFA�����·

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