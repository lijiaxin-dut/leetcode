#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

//You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
//
//Define a pair(u, v) which consists of one element from the first array and one element from the second array.
//
//Find the k pairs(u1, v1), (u2, v2) ...(uk, vk) with the smallest sums.
//
//Example 1:
//
//Input: nums1 = [1, 7, 11], nums2 = [2, 4, 6], k = 3
//	Output : [[1, 2], [1, 4], [1, 6]]
//	Explanation : The first 3 pairs are returned from the sequence :
//	   [1, 2], [1, 4], [1, 6], [7, 2], [7, 4], [11, 2], [7, 6], [11, 4], [11, 6]
//		   Example 2 :
//
//		   Input : nums1 = [1, 1, 2], nums2 = [1, 2, 3], k = 2
//		   Output : [1, 1], [1, 1]
//		   Explanation : The first 2 pairs are returned from the sequence :
//	   [1, 1], [1, 1], [1, 2], [2, 1], [1, 2], [2, 2], [1, 3], [1, 3], [2, 3]


//1.穷举出所有的可能，找出最小的k个
//2.从最小的开始找
//最开始在(0,0),产生两个(0,1)或者(1,0)  ，插入到最小堆中

//使用set去重







class Solution_373 {
public:

	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		if (nums1.size() == 0 || nums2.size() == 0)
			return{};
		auto compare = [](pair<int, vector<int>>a, pair<int, vector<int>>b) {return a.first>b.first; };
		priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, decltype(compare)>pq(compare);
		vector<vector<int>>rs;
		pq.push(make_pair(nums1[0] + nums2[0], vector<int>{0, 0}));
		set<pair<int, int>>visited;
		visited.insert(make_pair(0, 0));
		while (!pq.empty() && k>0) {
			k--;
			auto cur = pq.top();
			pq.pop();
			rs.push_back({ nums1[cur.second[0]],nums2[cur.second[1]] });

			if (cur.second[0] + 1<nums1.size() && visited.find(make_pair(cur.second[0] + 1, cur.second[1])) == visited.end()) {
				pq.push(make_pair(nums1[cur.second[0] + 1] + nums2[cur.second[1]], vector<int>{cur.second[0] + 1, cur.second[1]}));
				visited.insert(make_pair(cur.second[0] + 1, cur.second[1]));
			}
			if (cur.second[1] + 1<nums2.size() && visited.find(make_pair(cur.second[0], cur.second[1] + 1)) == visited.end()) {
				pq.push(make_pair(nums1[cur.second[0]] + nums2[cur.second[1] + 1], vector<int>{cur.second[0], cur.second[1] + 1}));
				visited.insert(make_pair(cur.second[0], cur.second[1] + 1));
			}
		}
		return rs;

	}

	vector<vector<int>> kSmallestPairs_1(vector<int>& nums1, vector<int>& nums2, int k) {

		auto compare = [](pair<int, vector<int>> a, pair<int, vector<int>>b) {return a.first > b.first; };

		priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, decltype(compare)>pq(compare);

		for (auto &one_num_1 : nums1) {
			for (auto &one_num_2 : nums2) {
				auto t = make_pair(one_num_1 + one_num_2, vector<int>{one_num_1, one_num_2});
				pq.push(t);
			}
		}

		vector<vector<int>>rs;

		while (!pq.empty() && rs.size() < k) {
			rs.push_back(pq.top().second);
			pq.pop();
		}
		return rs;
	
	}
};

//int main() {
//	Solution_373 s;
//	s.kSmallestPairs(vector<int>{1, 7, 11}, vector<int>{2, 4, 6}, 3);
//}