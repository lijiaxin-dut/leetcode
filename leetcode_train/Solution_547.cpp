#include<vector>

using namespace std;

//There are N students in a class.Some of them are friends, while some are not.Their friendship is transitive in nature.For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C.And we defined a friend circle is a group of students who are direct or indirect friends.
//
//Given a N*N matrix M representing the friend relationship between students in the class.If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not.And you have to output the total number of friend circles among all the students.
//
//Example 1 :
//Input:
//[[1, 1, 0],
//[1, 1, 0],
//[0, 0, 1]]
//Output : 2
//	Explanation : The 0th and 1st students are direct friends, so they are in a friend circle.
//	The 2nd student himself is in a friend circle.So return 2.

//并查集计算联通分量

//root[p_root]=q_root


class Solution_547 {
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
public:
	int findCircleNum(vector<vector<int>>& M) {
		int N = M.size();
		UF f(N);
		for (int i = 0; i<N; i++) {
			for (int j = i + 1; j<N; j++) {
				if (M[i][j] == 1) {
					f.unions(i, j);
				}
			}
		}
		return f.count;
	}
};