#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;


//Given a non - empty list of words, return the k most frequent elements.
//
//Your answer should be sorted by frequency from highest to lowest.If two words have the same frequency, then the word with the lower alphabetical order comes first.
//
//Example 1:
//Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
//	Output : ["i", "love"]
//	Explanation : "i" and "love" are the two most frequent words.
//	Note that "i" comes before "love" due to a lower alphabetical order.


//1.最大堆，返回前k个
//2.最小堆，始终保持k个，结果反序

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		auto compare = [](pair<int, string>a, pair<int, string>b) {
			return a.first>b.first || (a.first == b.first&&a.second<b.second);
		};
		priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(compare)>pq(compare);
		unordered_map<string, int>hash_map;
		for (auto &w : words) {
			hash_map[w]++;
		}
		for (auto &one_pair : hash_map) {
			pq.push(make_pair(one_pair.second, one_pair.first));
			if (pq.size()>k)
				pq.pop();
		}
		vector<string>rs;
		while (!pq.empty()) {
			rs.push_back(pq.top().second);
			pq.pop();
		}
		reverse(rs.begin(), rs.end());
		return rs;
	}
};