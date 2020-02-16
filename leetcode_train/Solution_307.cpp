#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;



//Given an integer array nums, find the sum of the elements between indices i and j(i ≤ j), inclusive.
//
//The update(i, val) function modifies nums by updating the element at index i to val.
//
//Example:
//
//Given nums = [1, 3, 5]
//
//sumRange(0, 2) -> 9
//update(1, 2)
//sumRange(0, 2) -> 8
//Note:
//
//The array is only modifiable by the update function.
//You may assume the number of calls to update and sumRange function is distributed evenly.


//将数组分块
//每一块的大小为  根号n
//保存每一块的求和

//发生更改时，只修改对应块的求和即可

//sumrange时，根据起始块和终止块划分，根据起点和终点是否在同一块中分组讨论
//


class NumArray {
	vector<vector<int>>c;
	vector<int>group_sum;
	int group_size = 0;
	int each_group_num = 0;
public:
	NumArray(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return;
		group_size = ceil(sqrt(n));
		each_group_num = group_size;
		c.resize(group_size, vector<int>(each_group_num));
		group_sum.resize(group_size);
		for (int i = 0; i<n; i++) {
			int row = i / each_group_num;
			int col = i%each_group_num;
			c[row][col] = nums[i];
		}
		for (int i = 0; i<group_size; i++) {
			group_sum[i] = accumulate(c[i].begin(), c[i].end(), 0);
		}

	}

	void update(int i, int val) {
		int row = i / each_group_num;
		int col = i%each_group_num;
		c[row][col] = val;
		group_sum[row] = accumulate(c[row].begin(), c[row].end(), 0);
	}

	int sumRange(int i, int j) {
		int sum = 0;
		int row_i = i / each_group_num;
		int col_i = i%each_group_num;
		int row_j = j / each_group_num;
		int col_j = j%each_group_num;
		if (row_i != row_j) {
			for (int cur = col_i; cur < each_group_num; cur++)
				sum += c[row_i][cur];
			for (int cur = row_i + 1; cur < row_j; cur++)
				sum += group_sum[cur];
			for (int cur = 0; cur <= col_j; cur++)
				sum += c[row_j][cur];
		}
		else {
			for (int cur = col_i; cur <= col_j; cur++)
				sum += c[row_i][cur];
		}
		return sum;
	}
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray* obj = new NumArray(nums);
* obj->update(i,val);
* int param_2 = obj->sumRange(i,j);
*/

/**
* Your NumArray object will be instantiated and called as such:
* NumArray* obj = new NumArray(nums);
* obj->update(i,val);
* int param_2 = obj->sumRange(i,j);
*/

/**
* Your NumArray object will be instantiated and called as such:
* NumArray* obj = new NumArray(nums);
* obj->update(i,val);
* int param_2 = obj->sumRange(i,j);
*/


