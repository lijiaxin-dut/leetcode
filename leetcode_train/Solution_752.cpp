#include<vector>
#include<queue>
#include<string>
#include<unordered_set>
#include<iostream>
using namespace std;



//You have a lock in front of you with 4 circular wheels.Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'.The wheels can rotate freely and wrap around : for example we can turn '9' to be '0', or '0' to be '9'.Each move consists of turning one wheel one slot.
//
//The lock initially starts at '0000', a string representing the state of the 4 wheels.
//
//You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.
//
//Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.
//
//Example 1:
//Input: deadends = ["0201", "0101", "0102", "1212", "2002"], target = "0202"
//	Output : 6
//	Explanation :
//	A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
//	Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
//	because the wheels of the lock become stuck after the display becomes the dead end "0102".
//


//使用unordered_set记录已经找到过的结果
//每一个节点有8个邻域


class Solution_752 {
public:
	int openLock(vector<string>& deadends, string target) {
		unordered_set<string>hash_map;
		for (auto &one_deadend : deadends) {
			hash_map.insert(one_deadend);
		}
		if (hash_map.count("0000") != 0)
			return -1;
		unordered_set<string>visited;
		visited.insert("0000");
		queue<string>q;
		q.push("0000");
		int rs = 0;
		while (!q.empty()) {
			int level_size = q.size();
			rs++;
			for (int s = 0; s<level_size; s++) {
				auto cur = q.front();
				q.pop();
				//四个位置，分别+1，-1
				for (int i = 0; i<4; i++) {
					string new_s_1 = cur;
					string new_s_2 = cur;
					if (new_s_1[i] == '9')  new_s_1[i] = '0';
					else   new_s_1[i] += 1;

					if (new_s_2[i] == '0')  new_s_2[i] = '9';
					else   new_s_2[i] -= 1;
					if (new_s_1 == target || new_s_2 == target)
						return rs;
					if (hash_map.count(new_s_1) == 0 && visited.count(new_s_1) == 0)
						q.push(new_s_1);
					if (hash_map.count(new_s_2) == 0 && visited.count(new_s_2) == 0)
						q.push(new_s_2);
					visited.insert(new_s_2);
					visited.insert(new_s_1);
				}
			}
		}
		return -1;
	}
};