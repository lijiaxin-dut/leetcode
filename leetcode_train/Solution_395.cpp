#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//1.找出所有的字串，判断每个字串是否符合要求
//2.分治
//对于[left,right]区间的字符串，跳过端点不满足要求的下标
//然后在中间找到一个不满足要求的点
//递归的查询

class Solution_395 {
public:
	int longestSubstring(string s, int k) {
		int n = s.size();
		int rs = 0;
		for (int left = 0; left<n; left++) {
			vector<int>hash_map(26, 0);
			int mark = 0;
			for (int i = left; i<n; i++) {
				int t = s[i] - 'a';
				hash_map[t]++;
				if (hash_map[t]<k)
					mark |= (1 << t);
				else
					mark &= ~(1 << t);
				if (mark == 0) {
					rs = max(rs, i - left + 1);
				}
			}
		}
		return rs;

	}
	int longestSubstring_d(string s, int k) {
		int n = s.size();
		if (n == 0 || k>n)
			return 0;
		return help(s, k, 0, n - 1);
	}
	int help(string &s, int k, int left, int right) {
		if (right - left + 1<k)
			return 0;
		unordered_map<int, int>hash_map;
		for (int i = left; i <= right; i++)
			hash_map[s[i] - 'a']++;

		while (right - left + 1 >= k&&hash_map[s[left] - 'a']<k)
			left++;
		while (right - left + 1 >= k&&hash_map[s[right] - 'a']<k)
			right--;

		for (int i = left; i <= right; i++) {
			if (hash_map[s[i] - 'a']<k)
				return max(help(s, k, left, i - 1), help(s, k, i + 1, right));
		}
		return right - left + 1;
	}
};
