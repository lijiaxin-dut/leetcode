#include<map>
#include<algorithm>

using namespace std;
//
//几乎每一个人都用 乘法表。但是你能在乘法表中快速找到第k小的数字吗？
//
//给定高度m 、宽度n 的一张 m * n的乘法表，以及正整数k，你需要返回表中第k 小的数字。
//
//例 1：
//
//输入 : m = 3, n = 3, k = 5
//	输出 : 3
//	解释 :
//	乘法表 :
//	1	2	3
//	2	4	6
//	3	6	9
//
//	第5小的数字是 3 (1, 2, 2, 3, 3).

//leetcode 378
//二分

class Solution {
public:
	int multi = 0;
	int findKthNumber(int m, int n, int k) {
		multi = m*n;
		int start = 1;
		int end = multi;
		while (start<end) {
			int mid = start + (end - start) / 2;
			pair<int, int>p = { 1, multi };
			int count = count_less_equal(m, n, mid, p);
			if (count == k)
				return p.first;
			if (count>k)
				end = p.first;
			else
				start = p.second;
		}
		return start;
	}

	int count_less_equal(int m, int n, int mid, pair<int, int>&p) {
		int row = 1;
		int col = n;
		int count = 0;
		while (col >= 1 && row <= m) {
			int col_row = col*row;
			if (col_row <= mid) {
				count += col;
				p.first = max(p.first, col_row);
				row++;
			}
			else {
				p.second = min(p.second, col_row);
				col--;
			}
		}
		return count;
	}
};