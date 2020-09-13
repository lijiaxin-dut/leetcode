#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


//你的面前有一堵方形的、由多行砖块组成的砖墙。 这些砖块高度相同但是宽度不同。你现在要画一条自顶向下的、穿过最少砖块的垂线。
//
//砖墙由行的列表表示。 每一行都是一个代表从左至右每块砖的宽度的整数列表。
//
//如果你画的线只是从砖块的边缘经过，就不算穿过这块砖。你需要找出怎样画才能使这条线穿过的砖块数量最少，并且返回穿过的砖块数量。
//
//你不能沿着墙的两个垂直边缘之一画线，这样显然是没有穿过一块砖的。

//方法1
//计算前缀和，按照最短的边的长度便利所有的长度
//如果又前缀和等于当前长度，就说明从空隙中穿过


//还是hash_map保存所有的前缀和
//选出前缀和出现次数最多的一个位置
//该位置说明穿过最少的砖

class Solution {
	
public:


	int leastBricks_2(vector<vector<int>>& wall) {
		int n = wall.size();
		unordered_map<int, int>hash_map;
		int max_cross = 0;
		for (auto &one_level : wall) {
			int sum = 0;
			for (int i = 0; i<one_level.size() - 1; i++) {
				sum += one_level[i];
				hash_map[sum]++;
				max_cross = max(max_cross, hash_map[sum]);
			}
		}
		return n - max_cross;
	}

	bool is_cross_wall(const vector<vector<int>>&pre_sum, int level, int index) {
		for (auto &one_index : pre_sum[level])
			if (one_index == index)
				return true;
		return false;
	}
	int leastBricks(vector<vector<int>>& wall) {
		int level = wall.size();
		int total_length = 0;
		for (int i = 0; i<wall[0].size(); i++)
			total_length += wall[0][i];
		vector<vector<int>>pre_sum(level);
		int min_length = INT_MAX;
		//计算前缀和
		for (int i = 0; i<level; i++) {
			for (int j = 0; j<wall[i].size(); j++) {
				min_length = min(min_length, wall[i][j]);
				if (j == 0)
					pre_sum[i].push_back(wall[i][j]);
				else
					pre_sum[i].push_back(wall[i][j] + pre_sum[i].back());
			}
		}
		int rs = INT_MAX;
		for (int i = 1; i<total_length; i += min_length) {
			int cur_rs = 0;
			for (int j = 0; j<level; j++) {
				if (is_cross_wall(pre_sum, j, i) == false)
					cur_rs++;
			}
			rs = min(rs, cur_rs);
		}
		return rs == INT_MAX ? level : rs;

	}
};