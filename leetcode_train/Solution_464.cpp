#include<vector>
#include<unordered_map>

using namespace std;

//在 "100 game" 这个游戏中，两名玩家轮流选择从 1 到 10 的任意整数，累计整数和，先使得累计整数和达到 100 的玩家，即为胜者。
//
//如果我们将游戏规则改为 “玩家不能重复使用整数” 呢？
//
//例如，两个玩家可以轮流从公共整数池中抽取从 1 到 15 的整数（不放回），直到累计整数和 >= 100。
//
//给定一个整数 maxChoosableInteger （整数池中可选择的最大数）和另一个整数 desiredTotal（累计和），判断先出手的玩家是否能稳赢（假设两位玩家游戏时都表现最佳）？
//
//你可以假设 maxChoosableInteger 不会大于 20， desiredTotal 不会大于 300。

//dfs
//如果当前求和>=target或者递归求和返回false
//	return true;
//递归求和代表的是对手先开始的返回值

class Solution {
	unordered_map<vector<bool>, bool>mark;
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (maxChoosableInteger >= desiredTotal)
			return true;
		if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
			return false;
		vector<bool> used(maxChoosableInteger + 1, false);
		return dfs(maxChoosableInteger, 0, desiredTotal, used);
	}
	bool dfs(int length, int total, int desiredTotal, vector<bool>& used) {
		if (mark.find(used) != mark.end())
			return mark[used];
		for (int i = 1; i <= length; i++) {
			if (used[i] == true)
				continue;
			used[i] = true;
			if (total + i >= desiredTotal || !dfs(length, total + i, desiredTotal, used)) {
				used[i] = false;
				mark[used] = true;
				return true;
			}
			used[i] = false;
		}
		mark[used] = false;
		return false;
	}
};