#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

//Given a non - empty array of integers, return the k most frequent elements.
//
//Example 1:
//
//Input: nums = [1, 1, 1, 2, 2, 3], k = 2
//	Output : [1, 2]

//使用优先队列
//优先队列里面保存pair

//自定义比较函数
//使用最小堆，始终保存k个数

class Solution_347 {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int>hash_map;
		for (int i = 0; i<nums.size(); i++)
			hash_map[nums[i]]++;
		auto compare = [](pair<int, int> a, pair<int, int> b) {return a.first>b.first; };
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)>pq(compare);
		for (auto &one_pair : hash_map) {
			pq.push(make_pair(one_pair.second, one_pair.first));
			if (pq.size()>k)
				pq.pop();
		}
		vector<int>rs;
		for (int i = 0; i<k; i++) {
			rs.push_back(pq.top().second);
			pq.pop();
		}
		reverse(rs.begin(), rs.end());
		return rs;
	}
};

//int main() {
//	Solution_347 s;
//	s.topKFrequent(vector<int>{1, 1, 1, 2, 2, 4, 5, 5},2);
//}