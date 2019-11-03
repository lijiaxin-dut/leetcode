#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<iterator>
#include<unordered_map>
using namespace std;

//
//Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
//
//Now, we would like to merge these accounts.Two accounts definitely belong to the same person if there is some email that is common to both accounts.Note that even if two accounts have the same name, they may belong to different people as people could have the same name.A person can have any number of accounts initially, but all of their accounts definitely have the same name.
//
//After merging the accounts, return the accounts in the following format : the first element of each account is the name, and the rest of the elements are emails in sorted order.The accounts themselves can be returned in any order.
//
//Example 1 :
//	Input :
//	accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
//	Output : [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'], ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
//	Explanation :
//	The first and third John's are the same person as they have the common email "johnsmith@mail.com".
//	The second John and Mary are different people as none of their email addresses are used by other accounts.
//	We could return these lists in any order, for example the answer[['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'],
//	['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

//并查集
//有交集认为在同一组

class Solution_721 {
	class UF {
	public:
		int count;
		vector<int>id;
		UF(int n) {
			count = n;
			id.resize(n, 0);
			for (int i = 0; i<n; i++)
				id[i] = i;
		}
		int find(int p) {
			int root = p;
			while (root != id[root])
				root = id[root];
			while (p != id[p]) {
				int t = id[p];
				id[p] = root;
				p = t;
			}
			return root;
		}
		void unions(int p, int q) {
			int p_root = find(p);
			int q_root = find(q);
			if (p_root == q_root)
				return;
			id[p_root] = q_root;
			count--;
		}

	};
	bool intersect(vector<vector<string>>& accounts, int i, int j) {
		for (int index = 1; index<accounts[i].size(); index++) {
			//cout<<accounts[i][index]<<endl;
			if (find(accounts[j].begin(), accounts[j].end(), accounts[i][index]) != accounts[j].end())
				return true;
		}
		return false;
	}

public:
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		int n = accounts.size();
		UF uf(n);
		for (int i = 0; i<n; i++) {
			for (int j = i + 1; j<n; j++) {
				if (intersect(accounts, i, j) == true) {
					uf.unions(i, j);
				}
			}
		}
		unordered_map<int, vector<string>>rs;
		for (int i = 0; i<n; i++) {
			int g_id = uf.find(i);
			if (rs[g_id].empty()) {
				rs[g_id] = accounts[i];
			}
			else {
				rs[g_id].insert(rs[g_id].end(), accounts[i].begin() + 1, accounts[i].end());
			}
		}
		vector<vector<string>>rs_v;
		for (auto &one : rs) {
			sort(one.second.begin() + 1, one.second.end());
			one.second.erase(unique(one.second.begin() + 1, one.second.end()), one.second.end());
			rs_v.push_back(one.second);
		}


		return rs_v;


	}
};
