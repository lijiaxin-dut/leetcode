#include<vector>

using namespace std;


//给你一个只包含 0 和 1 的 rows * columns 矩阵 mat ，请你返回有多少个 子矩形 的元素全部都是 1 。
//
//
//示例 1：
//
//输入：mat = [[1, 0, 1],
//[1, 1, 0],
//[1, 1, 0]]
//输出：13
//解释：
//有 6 个 1x1 的矩形。
//有 2 个 1x2 的矩形。
//有 3 个 2x1 的矩形。
//有 1 个 2x2 的矩形。
//有 1 个 3x1 的矩形。
//矩形数目总共 = 6 + 2 + 3 + 1 + 1 = 13 。
//示例 2：
//
//输入：mat = [[0, 1, 1, 0],
//[0, 1, 1, 1],
//[1, 1, 1, 0]]
//输出：24
//解释：
//有 8 个 1x1 的子矩形。
//有 5 个 1x2 的子矩形。
//有 2 个 1x3 的子矩形。
//有 4 个 2x1 的子矩形。
//有 2 个 2x2 的子矩形。
//有 2 个 3x1 的子矩形。
//有 1 个 3x2 的子矩形。
//矩形数目总共 = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24 。
class Solution {
public:
	int numSubmat(vector<vector<int>>& mat) {

		int m = mat.size();
		if (m == 0)
			return 0;
		int n = mat[0].size();
		vector<vector<int>>left(m, vector<int>(n, 0));
		for (int i = 0; i<m; i++) {
			int one_size = 0;
			for (int j = 0; j<n; j++) {
				if (mat[i][j] == 0) {
					one_size = 0;
				}
				else {
					one_size++;
				}
				left[i][j] = one_size;
			}
		}
		int rs = 0;
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				int min_val = INT_MAX;
				for (int k = i; k >= 0; k--) {
					min_val = min(min_val, left[k][j]);
					rs += min_val;
				}
			}
		}
		return rs;
	}
};