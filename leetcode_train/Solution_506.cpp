#include<string>
#include<queue>
using namespace std;

//Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals : "Gold Medal", "Silver Medal" and "Bronze Medal".
//
//Example 1 :
//	Input : [5, 4, 3, 2, 1]
//	Output : ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
//	Explanation : The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
//	For the left two athletes, you just need to output their relative ranks according to their scores.

class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {

		int n = nums.size();
		priority_queue<pair<int, int>>pq;
		for (int i = 0; i<n; i++)
			pq.push(make_pair(nums[i], i));
		vector<string>rs(n);
		for (int i = 0; i<n; i++) {
			if (i == 0)
				rs[pq.top().second] = "Gold Medal";
			else if (i == 1)
				rs[pq.top().second] = "Silver Medal";
			else if (i == 2)
				rs[pq.top().second] = "Bronze Medal";
			else
				rs[pq.top().second] = to_string(i + 1);
			pq.pop();
		}
		return rs;
	}
};