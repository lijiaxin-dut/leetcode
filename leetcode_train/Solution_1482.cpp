#include<vector>

using namespace std;


//二分搜索
//给一个mid值，判断经过mid天是否可以满足条件
//考虑不存在的情况

class Solution {
	bool check(vector<int>&bloomDay, int m, int k, int mid) {

		int size = 0;
		int len = 0;
		for (int i = 0; i<bloomDay.size(); i++) {
			if (bloomDay[i] <= mid) {
				len++;
				if (len == k) {
					len = 0;
					size++;
				}
			}
			else {
				len = 0;
			}
		}
		return size >= m;
	}
public:
	int minDays(vector<int>& bloomDay, int m, int k) {
		int left = 0;
		int right = 1e9 + 1;
		while (left<right) {
			int mid = left + (right - left) / 2;
			bool can_check = check(bloomDay, m, k, mid);
			if (can_check == true) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left == 1e9 + 1 ? -1 : left;
	}
};