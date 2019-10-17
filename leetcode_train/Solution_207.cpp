#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

//There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair : [0, 1]
//
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses ?
//
//Example 1 :
//
//	Input : 2, [[1, 0]]
//	Output : true
//	Explanation : There are a total of 2 courses to take.
//	To take course 1 you should have finished course 0. So it is possible.
//


//��������
//�ж��Ƿ��������޻�ͼ
//ʹ�ö���


class Solution_207 {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		int n = numCourses;
		queue<int>S;
		vector<vector<int>>graph(n);//���graph[i]����Щ�γ̵�����
		vector<int>count(n, 0);//��¼���޿γ̵�����
		for (int i = 0; i<prerequisites.size(); i++) {
			int cus = prerequisites[i][0];
			int pre = prerequisites[i][1];
			//pre�����޿γ�
			graph[pre].push_back(cus);
			count[cus]++;
		}
		for (int i = 0; i<n; i++) {
			if (count[i] == 0)
				S.push(i);
		}
		int count_cus = 0;
		while (!S.empty()) {
			int current_node = S.front();
			count_cus++;
			S.pop();
			//�������޿γ�Ϊcurrent node�Ŀγ�
			for (auto course : graph[current_node]) {
				count[course]--;
				if (count[course] == 0)
					S.push(course);
			}
		}
		return count_cus == n;

	}
};

//
//int main() {
//	Solution_207 s;
//	vector<vector<int>>pre{ {1,0} };
//	s.canFinish(2,pre);
//}