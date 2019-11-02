#include<vector>
#include<algorithm>



using namespace std;


In LeetCode Store, there are some kinds of items to sell.Each item has a price.

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



class Solution_638 {
public:
	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		int n = price.size();
		for (int i = 0; i<n; i++) {
			vector<int>t(n + 1, 0);
			t[i] = 1;
			t[n] = price[i];
			special.push_back(t);
		}

		int rs = INT_MAX;
		dfs(rs, n, 0, special, needs, 0);
		return rs;
	}
	bool check(vector<vector<int>>& special, vector<int>&needs, int index, int n) {
		for (int j = 0; j<n; j++)
			if (special[index][j]>needs[j])
				return false;
		return true;

	}
	bool check_1(vector<int>&needs, int n) {
		for (int j = 0; j<n; j++)
			if (needs[j] != 0)
				return false;
		return true;

	}
	void dfs(int &rs, int n, int current_price, vector<vector<int>>& special, vector<int>&needs, int current_index) {
		if (check_1(needs, n) == true) {
			rs = min(rs, current_price);
			return;
		}
		//剪枝
		if (current_price>rs)
			return;
		if (check(special, needs, current_index, n) == true) {
			for (int j = 0; j<n; j++)
				needs[j] -= special[current_index][j];
			dfs(rs, n, current_price + special[current_index].back(), special, needs, current_index);
			for (int j = 0; j<n; j++)
				needs[j] += special[current_index][j];
		}
		if (current_index + 1<special.size())
			dfs(rs, n, current_price, special, needs, current_index + 1);
	}
};