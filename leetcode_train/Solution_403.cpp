#include<map>
#include<random>
#include<vector>
#include<set>
#include<unordered_map>
#include<string>
#include<sstream>
#include<algorithm>
#include<unordered_set>
#include<iostream>
using namespace std;

//A frog is crossing a river.The river is divided into x units and at each unit there may or may not exist a stone.The frog can jump on a stone, but it must not jump into the water.
//
//Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.
//
//If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.
//
//Note:
//
//The number of stones is ¡Ý 2 and is < 1, 100.
//	Each stone's position will be a non-negative integer < 231.
//	The first stone's position is always 0.
//	Example 1 :
//
//	[0, 1, 3, 5, 6, 8, 12, 17]
//
//There are a total of 8 stones.
//The first stone at the 0th unit, second stone at the 1st unit,
//third stone at the 3rd unit, and so on...
//The last stone at the 17th unit.
//
//Return true.The frog can jump to the last stone by jumping
//1 unit to the 2nd stone, then 2 units to the 3rd stone, then
//2 units to the 4th stone, then 3 units to the 6th stone,
//4 units to the 7th stone, and 5 units to the 8th stone.

//×Ôµ×ÏòÉÏµÝ¹é+memory

class Solution_403 {
public:
	bool canCross(vector<int>& stones) {

		if (stones.size() <= 1)
			return true;
		if (stones[1]>1)
			return false;
		unordered_map<int, unordered_map<int, int>>c;
		set<int>s(stones.begin(), stones.end());
		return dfs(c, 1, 1, s) == 1;
	}
	int dfs(unordered_map<int, unordered_map<int, int>>&c, int cur_index, long last_length, set<int>& stones) {
		auto it = c.find(cur_index);
		if (it != c.end() && it->second.find(last_length) != it->second.end())
			return  c[cur_index][last_length];
		if (cur_index == *stones.rbegin())
			return 1;


		int next_index = cur_index + last_length;
		int rs_1 = 0;
		if (stones.find(next_index) != stones.end())
			rs_1 = dfs(c, next_index, last_length, stones);

		int rs_2 = 0;
		int next_index_1 = cur_index + last_length - 1;
		if (stones.find(next_index_1) != stones.end() && last_length != 1 && rs_1 == 0)
			rs_2 = dfs(c, next_index_1, last_length - 1, stones);


		int next_index_2 = cur_index + last_length + 1;
		bool rs_3 = 0;
		if (stones.find(next_index_2) != stones.end() && rs_1 == 0 && rs_2 == 0)
			rs_1 = dfs(c, next_index_2, last_length + 1, stones);

		c[cur_index][last_length] = rs_1 | rs_2 | rs_3;
		return  c[cur_index][last_length];


	}
};