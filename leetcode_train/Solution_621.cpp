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


//每一轮优先考虑次数多的task开始执行
//使用优先队列记录次数
//弹出的task,如果次数不为0
//需要重新push进去优先队列


class Solution_621 {
public:
	int leastInterval(vector<char>& tasks, int n) {
		int rs = 0;
		int cycle = n + 1;
		unordered_map<char, int>m;
		for (auto &one_char : tasks)
			m[one_char]++;
		//优先队列保存每个char出现的次数
		priority_queue<int>q;
		for (auto &one_char : m)
			q.push(one_char.second);
		//每次优先选择出现次数最多的job开始执行
		while (!q.empty()) {
			int cnt = 0;
			vector<int>temp;//保存本轮的job
			//把弹出的job的次数保存下来
			for (int i = 0; i<cycle; i++) {
				if (!q.empty()) {
					temp.push_back(q.top());
					q.pop();
					++cnt;
				}
			}
			//弹出的job没有执行完毕
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