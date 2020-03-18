#include<vector>
#include<unordered_map>
#include<algorithm>


using namespace std;

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
		//使用并查集对所有的账户进行合并
		unordered_map<string, int>s;
		for (auto &one_account : accounts) {
			for (int i = 1; i<one_account.size(); i++) {
				if (s.count(one_account[i]) == 0)
					s[one_account[i]] = s.size();
			}
		}
		UF uf(s.size());
		for (auto &one_account : accounts) {
			for (int i = 1; i<one_account.size() - 1; i++) {
				uf.unions(s[one_account[i]], s[one_account[i + 1]]);
			}
		}

		vector<vector<string>>rs;
		for (auto &one_account : accounts) {
			vector<string>new_account{ one_account[0] };//当前新的账号
			//当前顾客还有账户，就需要新开一个账户
			if (s.find(one_account[1]) != s.end()) {
				int cur_root = uf.find(s[one_account[1]]);
				s.erase(one_account[1]);
				new_account.push_back(one_account[1]);
				for (auto &one : s) {
					if (cur_root == uf.find(one.second)) {
						new_account.push_back(one.first);
					}
				}
				for (int i = 1; i<new_account.size(); i++)
					s.erase(new_account[i]);
			}
			if (new_account.size() > 1) {
				sort(new_account.begin() + 1, new_account.end());
				rs.push_back(new_account);
			}
		}
		return rs;

	}
};