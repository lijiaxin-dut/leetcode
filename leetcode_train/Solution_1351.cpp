#include<vector>

using namespace std;

//Given a m * n matrix grid which is sorted in non - increasing order both row - wise and column - wise.
//
//Return the number of negative numbers in grid.
//
//
//
//Example 1:
//
//Input: grid = [[4, 3, 2, -1], [3, 2, 1, -1], [1, 1, -1, -2], [-1, -1, -2, -3]]
//	Output : 8
//	Explanation : There are 8 negatives number in the matrix.

//�����½ǿ�ʼ����
//����������<0��˵���ڵ�ǰ�У���λ�ú󣬶�С��<0   r--
//���ĳһ�ж�>0 ,���������

class Solution_1351 {
public:
	int countNegatives(vector<vector<int>>& grid) {
		int rs = 0;
		int m = grid.size();
		if (m == 0)
			return 0;
		int n = grid[0].size();
		int r = m - 1;
		int c = 0;
		while (r >= 0 && c<n) {
			if (grid[r][c]<0) {
				r--;
				rs += n - c;
			}
			else {
				c++;
			}
		}
		return rs;

	}

};