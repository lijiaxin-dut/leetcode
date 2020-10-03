#include<vector>
#include<algorithm>
using namespace std;

//传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。
//传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。
//返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。
//
//
//示例 1：
//输入：weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], D = 5
//输出：15
//解释：
//船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
//第 1 天：1, 2, 3, 4, 5
//第 2 天：6, 7
//第 3 天：8
//第 4 天：9
//第 5 天：10
//请注意，货物必须按照给定的顺序装运，因此使用载重能力为 14 的船舶并将包装分成(2, 3, 4, 5), (1, 6, 7), (8), (9), (10) 是不允许的。


//1.dfs+备忘录,超时
//2.二分搜索
//对于一艘承载力为K船来说，我们必然会在不超过其承载力的前提下贪心地往上装载货物，这样才能使得运送包裹所花费的时间最短。
//如果船在承载力为K的条件下可以完成在D天内送达包裹的任务，那么任何承载力大于K的条件下依然也能完成任务
//我们可以让这个承载力K从max(weights)max(weights)开始（即所有包裹中质量最大包裹的重量，低于这个重量我们不可能完成任务），逐渐增大承载力K，直到K可以让我们在D天内送达包裹。此时K即为我们所要求的最低承载力。

class Solution_binary_search {
	bool can_ship(vector<int>&weights, int D, int K) {
		int sum = 0;
		for (int i = 0; i<weights.size(); i++) {
			if (weights[i]>K)
				return false;
			sum += weights[i];
			if (sum>K) {
				D--;
				sum = weights[i];
			}
		}
		return D>0;
	}
public:
	int shipWithinDays(vector<int>& weights, int D) {
		int left = 0;
		int right = 0;
		for (auto c : weights) {
			left = max(left, c);
			right += c;
		}
		while (left<right) {
			int mid = left + (right - left) / 2;
			bool is_ship = can_ship(weights, D, mid);
			if (is_ship == true) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
};
class Solution {
public:
	int shipWithinDays(vector<int>& weights, int D) {
		int n = weights.size();
		vector<int>pre_sum(n, 0);
		pre_sum[0] = weights[0];
		for (int i = 1; i<n; i++) {
			pre_sum[i] = pre_sum[i - 1] + weights[i];
		}
		vector<vector<int>>c(n, vector<int>(D + 1, -1));
		return dfs(weights, D, pre_sum, 0, n, c);
	}
	int dfs(vector<int>&nums, int D, vector<int>&pre_sum, int cur_index, int n, vector<vector<int>>&c) {
		if (cur_index == n) {
			return 0;
		}
		if (D == 1) {
			return pre_sum[n - 1] - pre_sum[cur_index] + nums[cur_index];
		}
		if (c[cur_index][D] != -1)
			return c[cur_index][D];
		int rs = INT_MAX;
		for (int i = cur_index; i<n; i++) {
			int cur_val = max(pre_sum[i] - pre_sum[cur_index] + nums[cur_index], dfs(nums, D - 1, pre_sum, i + 1, n, c));
			rs = min(rs, cur_val);
		}
		c[cur_index][D] = rs;
		return rs;
	}
};