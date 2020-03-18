#include<vector>
#include<unordered_map>
#include<string>
#include<set>

using namespace std;


//You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0 - indexed) of the string.
//
//You can swap the characters at any pair of indices in the given pairs any number of times.
//
//Return the lexicographically smallest string that s can be changed to after using the swaps.
//

//并查集，每个连通域内，从小到达依次放入相应的位置

class UF
{
public:
	vector<int> id;

	UF(int N)
	{
		id.resize(N);
		for (int i = 0; i < N; i++) {
			id[i] = i;
		}
	}

	int find(int p) {
		int root = p;
		while (root != id[root]) {
			root = id[root];
		}
		while (p != id[p]) {
			int temp = id[p];
			id[p] = root;
			p = temp;
		}
		return root;
	}

	bool connected(int p, int q) {
		return find(p) == find(q);
	}
	void connect(int p, int q) {
		int i = find(p);
		int j = find(q);
		if (i == j)
			return;
		id[i] = j;
	}
};

class Solution {
public:
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
		int n = s.size();
		UF un(n);
		for (auto &one_pair : pairs) {
			if (one_pair[0] != one_pair[1])
				un.connect(one_pair[0], one_pair[1]);
		}

		unordered_map<int, multiset<char>>m;
		for (int i = 0; i<n; i++) {
			m[un.find(i)].insert(s[i]);
		}

		string rs;
		for (int i = 0; i<n; i++) {
			int root = un.find(i);
			rs += *m[root].begin();
			m[root].erase(m[root].begin());
		}
		return rs;




	}
};
