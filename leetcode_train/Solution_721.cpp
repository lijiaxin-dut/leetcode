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

class UF {
public:
	vector<int>root;
	int count;
	UF(int n) {
		count = n;
		root.resize(n);
		for (int i = 0; i<n; i++)
			root[i] = i;
	}
	int find(int p) {
		int p_root = p;
		while (p_root != root[p_root])
			p_root = root[p_root];
		while (p != root[p]) {
			int back = root[p];
			root[p] = p_root;
			p = back;
		}
		return p_root;
	}
	void unions(int p, int q) {
		int p_root = find(p);
		int q_root = find(q);
		if (p_root == q_root)
			return;
		root[p_root] = q_root;
		count--;
	}
};


class Solution {
public:
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		unordered_map<string, int>email_to_index;
		unordered_map<int, string>index_to_email;
		unordered_map<int, string>index_to_name;
		for (auto &one_account : accounts) {
			for (int i = 1; i<one_account.size(); i++) {
				if (email_to_index.count(one_account[i]) == 0) {
					int cur_size= email_to_index.size();
					email_to_index[one_account[i]] = cur_size;
					index_to_email[cur_size] = one_account[i];
					index_to_name[cur_size] = one_account[0];
				}
			}
		}
		UF uf(email_to_index.size());
		for (auto &one_account : accounts) {
			for (int i = 1; i<one_account.size() - 1; i++) {
				uf.unions(email_to_index[one_account[i]], email_to_index[one_account[i + 1]]);
			}
		}
		vector<vector<string>>rs;
		unordered_map<int, vector<int>>group;
		for (int i = 0; i<uf.root.size(); i++) {
			group[uf.find(i)].push_back(i);
		}
		for (auto &one_pair : group) {
			vector<string>one_group;
			one_group.push_back(index_to_name[one_pair.second[0]]);
			for (auto &one_group_id : one_pair.second) {
				one_group.push_back(index_to_email[one_group_id]);
			}
			sort(one_group.begin(), one_group.end());
			rs.push_back(one_group);
		}
		return rs;


	}
};

int main() {

	vector<vector<string>>m{ {
			"John", "johnsmith@mail.com", "john_newyork@mail.com"},
			{"John", "johnsmith@mail.com", "john00@mail.com"},
			{"Mary", "mary@mail.com"},{"John", "johnnybravo@mail.com"} };
	Solution s;
	s.accountsMerge(m);


}