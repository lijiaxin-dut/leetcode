#include<vector>
#include<algorithm>
#include<queue>
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


//注意去重

//遇到(3,2),新的坐标为(3,3)和(4,2)
//遇到(2,3),新的坐标为(3,3)和(2,4)
//(3,3)出现了两次，
// i,j you just need to push i+1, j into queue. i, j+1 can be pushed into queue later when you see i - 1, j + 1
//当i==0时，没有i-1，所以需要单独考虑







class Solution_373 {
public:

	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

		vector<vector<int>>rs;

		if (nums1.size() == 0 || nums2.size() == 0 || k == 0)
			return rs;
		auto compare = [&nums1, &nums2](pair<int, int> a, pair<int, int>b)
		{return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]; };

		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)>pq(compare);

		pq.push(make_pair(0, 0));

		while (k-->0 && !pq.empty()) {
			auto p = pq.top();
			pq.pop();
			rs.push_back(vector<int>{nums1[p.first], nums2[p.second]});
			if (p.first + 1<nums1.size()) {
				pq.push(make_pair(p.first + 1, p.second));
			}
			if (p.first == 0 && p.second + 1<nums2.size()) {
				pq.push(make_pair(p.first, p.second + 1));
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