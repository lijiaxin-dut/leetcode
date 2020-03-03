#include<queue>
#include<string>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int>count;
		for (auto &one_char : s)
			count[one_char]++;
		priority_queue<pair<int, char>, vector<pair<int, char>>>pq;
		for (auto &one_group : count) {
			pq.push(make_pair(one_group.second, one_group.first));
		}
		string rs;
		while (!pq.empty()) {
			auto cur = pq.top();
			pq.pop();
			rs += string(cur.first, cur.second);
		}
		return rs;
	}
};