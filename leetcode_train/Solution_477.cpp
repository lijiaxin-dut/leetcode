#include<vector>
#include<memory>
#include<utility>
using namespace std;



class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		vector<pair<int, int>>count(32, { 0,0 });
		for (int i = 0; i<nums.size(); i++) {
			for (int j = 0; j<32; j++) {
				if ((nums[i] >> j) & 1)
					count[j].first++;
				else
					count[j].second++;
			}
		}
		int rs = 0;
		for (int i = 0; i<32; i++)
			rs += count[i].first*count[i].second;
		return rs;

	}
};