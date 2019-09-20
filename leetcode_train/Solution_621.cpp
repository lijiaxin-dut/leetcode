#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

//Given a char array representing tasks CPU need to do.It contains capital 
//letters A to Z where different letters represent different tasks.Tasks could be 
//done without original order.Each task could be done in one interval.For each interval, 
//CPU could finish one task or just be idle.
//
//However, there is a non - negative cooling interval n that means between two same tasks, 
//there must be at least n intervals that CPU are doing different tasks or just be idle.
//
//You need to return the least number of intervals the CPU will take to finish all the given tasks.

//Example:
//
//Input: tasks = ["A", "A", "A", "B", "B", "B"], n = 2
//	Output : 8
//	Explanation : A->B->idle->A->B->idle->A->B.


//ÿһ�����ȿ��Ǵ������task��ʼִ��
//ʹ�����ȶ��м�¼����
//������task,���������Ϊ0
//��Ҫ����push��ȥ���ȶ���


class Solution_621 {
public:
	int leastInterval(vector<char>& tasks, int n) {
		int rs = 0;
		int cycle = n + 1;
		unordered_map<char, int>m;
		for (auto &one_char : tasks)
			m[one_char]++;
		//���ȶ��б���ÿ��char���ֵĴ���
		priority_queue<int>q;
		for (auto &one_char : m)
			q.push(one_char.second);
		//ÿ������ѡ����ִ�������job��ʼִ��
		while (!q.empty()) {
			int cnt = 0;
			vector<int>temp;//���汾�ֵ�job
			//�ѵ�����job�Ĵ�����������
			for (int i = 0; i<cycle; i++) {
				if (!q.empty()) {
					temp.push_back(q.top());
					q.pop();
					++cnt;
				}
			}
			//������jobû��ִ�����
			for (auto &new_char_times : temp) {
				if (--new_char_times>0)
					q.push(new_char_times);
			}
			if (q.empty())
				rs += cnt;
			else
				rs += cycle;
		}
		return rs;
	}
};
//int main() {
//	Solution_621 s;
//	vector<char>test{ 'A','A','A','B','B','B' };
//	s.leastInterval(test, 2);
//
//	
//}