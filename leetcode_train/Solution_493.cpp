#include<vector>

using namespace std;

//Given an array nums, we call(i, j) an important reverse pair if i < j and nums[i] > 2 * nums[j].
//
//You need to return the number of important reverse pairs in the given array.


//�鲢����

//��merge֮ǰ��ͳ�Ƶ�ǰ�Ľ��
//����ÿһ��i���ҵ����һ������������j
//��[mid+1,j-1]�������������Ľ��


class Solution {
	vector<int>aux;
	int rs = 0;
public:
	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		aux.resize(n, 0);
		vector<long>temp(nums.begin(), nums.end());
		merge(temp, 0, n - 1);
		return rs;
	}
	void merge(vector<long>& nums, int left, int right) {
		if (left<right) {
			int mid = left + (right - left) / 2;
			merge(nums, left, mid);
			merge(nums, mid + 1, right);
			merge_help(nums, left, mid, right);
		}
	}
	void merge_help(vector<long>& nums, int left, int mid, int right) {
		int l_s = left;
		int r_s = mid + 1;
		for (int i = left, j = mid + 1; i <= mid; i++) {
			while (j <= right&&nums[i] / 2.0>nums[j])
				j++;
			rs += j - mid - 1;
		}
		for (int cur_index = left; cur_index <= right; cur_index++) {
			if (l_s == mid + 1) {
				aux[cur_index] = nums[r_s++];
			}
			else if (r_s == right + 1) {
				aux[cur_index] = nums[l_s++];
			}
			else if (nums[l_s] <= nums[r_s]) {
				aux[cur_index] = nums[l_s++];
			}
			else {
				aux[cur_index] = nums[r_s++];
			}
		}
		for (int cur_index = left; cur_index <= right; cur_index++) {
			nums[cur_index] = aux[cur_index];
		}

	}

};