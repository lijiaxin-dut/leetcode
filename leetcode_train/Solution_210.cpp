#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

//There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair : [0, 1]
//
//Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
//
//There may be multiple correct orders, you just need to return one of them.If it is impossible to finish all courses, return an empty array.
//
//Example 1:
//
//Input: 2, [[1, 0]]
//	Output : [0, 1]
//	Explanation : There are a total of 2 courses to take.To take course 1 you should have finished
//	course 0. So the correct course order is[0, 1] .

//�����������������ҵ���������



class Solution_210 {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
		vector<int>rs;
		while (!S.empty()) {
			int current_node = S.front();
			S.pop();
			rs.push_back(current_node);
			//�������޿γ�Ϊcurrent node�Ŀγ�
			for (auto course : graph[current_node]) {
				count[course]--;
				if (count[course] == 0)
					S.push(course);
			}
		}
		if (rs.size() == n)
			return rs;
		return{};
	}
};