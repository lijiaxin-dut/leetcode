#include<vector>
#include<algorithm>
#include<queue>
#include<set>
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




class Solution {
public:

	int kthSmallest_heap(vector<vector<int>>& matrix, int k) {
		int m = matrix.size();
		if (m == 0)
			return 0;
		int n = matrix[0].size();
		auto compare = [&](pair<int, int>a, pair<int, int>b) {return matrix[a.first][a.second]>matrix[b.first][b.second]; };
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)>pq(compare);
		set<pair<int, int>>visited;
		visited.insert(make_pair(0, 0));
		pq.push(make_pair(0, 0));
		int rs = 0;
		while (!pq.empty() && k>0) {
			auto cur = pq.top();
			pq.pop();
			k--;
			rs = matrix[cur.first][cur.second];
			if (cur.first + 1<m&&visited.find(make_pair(cur.first + 1, cur.second)) == visited.end()) {
				pq.push(make_pair(cur.first + 1, cur.second));
				visited.insert(make_pair(cur.first + 1, cur.second));
			}
			if (cur.second + 1<n&&visited.find(make_pair(cur.first, cur.second + 1)) == visited.end()) {
				pq.push(make_pair(cur.first, cur.second + 1));
				visited.insert(make_pair(cur.first, cur.second + 1));
			}
		}
		return rs;
	}


	//按照数字范围进行二分
	//给定一个mid,统计<=mid的个数 ，计数为count
	//统计过程中，保存最接近mid的两个数，一个<mid  l,一个>mid r
	//count==k,返回r
	//count<k  left=r
	//count>k  right=l
	int kthSmallest(vector<vector<int>> &matrix, int k) {
		int n = matrix.size();
		int start = matrix[0][0], end = matrix[n - 1][n - 1];
		while (start < end) {
			int mid = start + (end - start) / 2;
			pair<int, int> smallLargePair = { matrix[0][0], matrix[n - 1][n - 1] };
			int count = countLessEqual(matrix, mid, smallLargePair);
			if (count == k) {
				return smallLargePair.first;
			}

			if (count < k) {
				start = smallLargePair.second;
			}
			else {
				end = smallLargePair.first;
			}
		}


		return start;
	}

	int countLessEqual(vector<vector<int>> &matrix, int mid, pair<int, int> &smallLargePair) {
		int count = 0;
		int n = matrix.size();
		for (int row = 0; row<n; row++) {
			for (int col = 0; col<n; col++) {
				if (matrix[row][col] > mid) {
					smallLargePair.second = min(smallLargePair.second, matrix[row][col]);
				}
				else {
					smallLargePair.first = max(smallLargePair.first, matrix[row][col]);
					count++;
				}

			}

		}
		return count;
	}
};