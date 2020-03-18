#include<vector>
#include<algorithm>



using namespace std;


//In LeetCode Store, there are some kinds of items to sell.Each item has a price.

//However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.
//
//You are given the each item's price, a set of special offers, and the number we need to buy for each item. The job is to output the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers.
//
//Each special offer is represented in the form of an array, the last number represents the price you need to pay for this special offer, other numbers represents how many specific items you could get if you buy this offer.
//
//You could use any of special offers as many times as you want.
//
//Example 1:
//Input: [2, 5], [[3, 0, 5], [1, 2, 10]], [3, 2]
//	Output : 14
//	Explanation :
//	There are two kinds of items, A and B.Their prices are $2 and $5 respectively.
//	In special offer 1, you can pay $5 for 3A and 0B
//	In special offer 2, you can pay $10 for 1A and 2B.
//	You need to buy 3A and 2B, so you may pay $10 for 1A and 2B(special offer #2), and $4 for 2A.


//单个物品也看作是礼包，同理处理
//加上剪枝



class Solution {
	int rs = 0;
public:
	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		rs = INT_MAX;
		int n = price.size();
		for (int i = 0; i<n; i++) {
			vector<int>singal(n + 1);
			singal[i] = 1;
			singal[n] = price[i];
			special.push_back(singal);
		}
		dfs(special, needs, 0, 0);
		return rs;
	}
	void minus(vector<int> &bag, vector<int>& needs) {
		for (int i = 0; i<needs.size(); i++) {
			needs[i] -= bag[i];
		}
	}
	void add(vector<int> &bag, vector<int>& needs) {
		for (int i = 0; i<needs.size(); i++) {
			needs[i] += bag[i];
		}
	}
	bool satisfy(vector<int> &bag, vector<int>& needs) {
		for (int i = 0; i<needs.size(); i++) {
			if (bag[i]>needs[i])
				return false;
		}
		return true;
	}
	bool find_rs(vector<int>& needs) {
		int n = needs.size();
		for (int i = 0; i<n; i++) {
			if (needs[i] != 0) {
				return false;
			}
		}
		return true;
	}
	void dfs(vector<vector<int>>& special, vector<int>& needs, int cur_total, int cur_index) {
		if (cur_total>rs || cur_index >= special.size())
			return;
		if (find_rs(needs) == true) {
			rs = min(rs, cur_total);
			return;
		}
		if (satisfy(special[cur_index], needs)) {
			minus(special[cur_index], needs);
			dfs(special, needs, cur_total + special[cur_index].back(), cur_index);
			add(special[cur_index], needs);
		}
		dfs(special, needs, cur_total, cur_index + 1);
	}
};