#include<vector>
#include<algorithm>
using namespace std;

//Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
//
//Note that it is the kth smallest element in the sorted order, not the kth distinct element.
//
//Example:
//
//matrix = [
//	[1, 5, 9],
//		[10, 11, 13],
//		[12, 13, 15]
//],
//k = 8,
//
//return 13.

//左上角为最小的数字
//右下角为最大的数字

//统计小于<=mid元素的个数
//如果cnt<k  则在mid+1,right之间
//如果cnt>=k   则在left,mid之间


class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {

		int n = matrix.size();
		int left = matrix[0][0];
		int right = matrix[n - 1][n - 1];


		while (left<right) {
			int mid = (right + left) / 2;
			int num = 0;
			for (int i = 0; i<n; i++)
				num += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
			if (num<k) {
				left = mid + 1;
			}
			else
				right = mid;
		}
		return left;



	}
};