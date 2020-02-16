#include<vector>
#include<algorithm>
using namespace std;
//Assume you are an awesome parent and want to give your children some cookies.But, you should give each child at most one cookie.Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj.If sj >= gi, we can assign the cookie j to the child i, and the child i will be content.Your goal is to maximize the number of your content children and output the maximum number.
//
//Note:
//You may assume the greed factor is always positive.
//You cannot assign more than one cookie to one child.

//贪心
//从小到达排序，一次分配

class Solution_455 {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		int rs = 0;
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int s_index = 0;
		for (int i = 0; i<g.size(); i++) {
			while (s_index<s.size()) {
				if (s[s_index++] >= g[i]) {
					rs++;
					break;
				}

			}
		}
		return rs;
	}
};