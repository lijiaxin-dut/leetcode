#include<vector>

using namespace std;


//In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a / , \, or blank space.These characters divide the square into contiguous regions.
//
//(Note that backslash characters are escaped, so a \ is represented as "\\".)
//
//Return the number of regions.
//
//
//
//Example 1:
//
//Input:
//[
//	" /",
//	"/ "
//]
//Output : 2

//把每一块分成四块，按顺序标号
//	0
//1		3
//	2

//Two adjacent parts in different cells are contiguous regions.
//In case '/', top and left are contiguous, botton and right are contiguous.
//In case '\\', top and right are contiguous, bottom and left are contiguous.
//In case ' ', all 4 parts are contiguous.

class Solution_959 {
	class UF {
	public:
		int count;
		vector<int>id;
		UF(int n) {
			count = n;
			id.resize(n);
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
	int g(int n, int i, int j, int k) {
		return (i * n + j) * 4 + k;
	}
public:
	int regionsBySlashes(vector<string>& grid) {
		int n = grid.size();
		int count = n*n * 4;
		UF uf(count);
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				if (i>0) {
					uf.unions(g(n, i, j, 0), g(n, i - 1, j, 2));
				}
				if (j>0) {
					uf.unions(g(n, i, j, 1), g(n, i, j - 1, 3));
				}
				if (grid[i][j] == '/') {
					uf.unions(g(n, i, j, 0), g(n, i, j, 1));
					uf.unions(g(n, i, j, 2), g(n, i, j, 3));
				}
				if (grid[i][j] == '\\') {
					uf.unions(g(n, i, j, 0), g(n, i, j, 3));
					uf.unions(g(n, i, j, 2), g(n, i, j, 1));
				}
				if (grid[i][j] == ' ') {
					uf.unions(g(n, i, j, 0), g(n, i, j, 1));
					uf.unions(g(n, i, j, 0), g(n, i, j, 2));
					uf.unions(g(n, i, j, 0), g(n, i, j, 3));
				}

			}
		}
		return uf.count;
	}
};