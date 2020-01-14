#include<iostream>
#include<vector>
#include<queue>

using namespace std;


//Given an array of non - negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.


//bfs
//用start和end表示下一轮要遍历的节点，一定是连续的
//max_end表示在一步内，[start,end]之间最远的index为max_end
//下一轮的start=end+1
//end=max_end



class Solution_45 {
public:
	int jump_bfs_fast(vector<int>& nums) {
		int n = nums.size(), rs = 0, start = 0, end = 0;
		while (end<n - 1) {
			rs++;
			int max_end = 0;
			for (int i = start; i <= end; i++) {
				if (i + nums[i] >= n - 1)
					return rs;
				max_end = max(max_end, i + nums[i]);
			}
			start = end + 1;
			end = max_end;
		}
		return rs;
	}
	int jump_bfs_slow(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1)
			return 0;
		vector<int>mark(n, 0);
		mark[0] = 1;
		queue<int>next_node;
		next_node.push(0);
		int rs = 0;
		while (!next_node.empty()) {
			rs++;
			int pre_size = next_node.size();
			for (int k = 0; k<pre_size; k++) {
				int cur_index = next_node.front();
				next_node.pop();
				for (int j = cur_index + 1; j<n&&j <= cur_index + nums[cur_index]; j++) {
					if (mark[j] == 0) {
						next_node.push(j);
						mark[j] = 1;
					}
				}
			}
			if (mark[n - 1] == 1)
				break;
		}
		return rs;



	}
};