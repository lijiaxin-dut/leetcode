#include<vector>
#include<memory>
#include<iostream>

using namespace std;


//You are given an integer array nums and you have to return a new counts array.The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
//
//Example:
//
//Input: [5, 2, 6, 1]
//	Output : [2, 1, 1, 0]
//	Explanation :
//	To the right of 5 there are 2 smaller elements(2 and 1).
//	To the right of 2 there is only 1 smaller element(1).
//	To the right of 6 there is 1 smaller element(1).
//	To the right of 1 there is 0 smaller element.


//�鲢����
//��Ϊ��Ҫͳ�ƶ�Ӧ�����ĸ���
//ʹ��pair�������ݣ�

//�ڹ鲢��������У���nums[left]<=nums[right],˵��[mid+1,right-1]֮�䶼<nums[left]
//����Ϊright-mid-1
//���Ҳ��������ʱ����������֮���ÿһλ��<�Ҳ�����

class Solution_315 {
	vector<pair<int, int>>merge_sort_help;
	vector<int>rs;
public:
	vector<int> countSmaller(vector<int>& vec) {
		int n = vec.size();

		vector<pair<int, int>> nums;
		for (int i = 0; i < vec.size(); i++) {
			nums.emplace_back(vec[i], i);
		}

		merge_sort_help.resize(n);
		rs.resize(n, 0);
		merge(nums, 0, n - 1);
		return rs;
	}

	void merge(vector<pair<int, int>>&nums, int lo, int hi) {
		if (hi <= lo)
			return;
		int mid = lo + (hi - lo) / 2;
		merge(nums, lo, mid);
		merge(nums, mid + 1, hi);
		merge_sort(nums, lo, mid, hi);
	}
	void merge_sort(vector<pair<int, int>>&nums, int lo, int mid, int hi) {
		//[lo,mid]
		//[mid+1,hi]
		int cur_index = lo;
		int l_s = lo;
		int r_s = mid + 1;
		for (int cur_index = lo; cur_index <= hi; cur_index++) {
			if (l_s == mid + 1) {
				merge_sort_help[cur_index] = nums[r_s++];
			}
			else if (r_s == hi + 1) {
				rs[nums[l_s].second] += r_s - mid - 1;
				merge_sort_help[cur_index] = nums[l_s++];

			}
			//r_s����Ϊ���ڵ���l_s��������λ�ã�С��r_s��λ��һ��С��nums[l_s]
			else if (nums[l_s].first <= nums[r_s].first) {
				rs[nums[l_s].second] += r_s - mid - 1;
				merge_sort_help[cur_index] = nums[l_s++];
			}
			else {
				merge_sort_help[cur_index] = nums[r_s++];
			}
		}
		for (int cur_index = lo; cur_index <= hi; cur_index++) {
			nums[cur_index] = merge_sort_help[cur_index];
		}
	}

};