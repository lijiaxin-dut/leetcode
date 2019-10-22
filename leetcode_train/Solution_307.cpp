#include<vector>

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

//sumrange时，根据起始块和终止块划分



class NumArray {
	vector<int>blocks;
	vector<int>num;
	int b_size;
public:
	NumArray(vector<int>& nums) :num(nums) {
		int n = nums.size();
		if (n == 0)
			return;
		b_size = ceil(n / sqrt(n));
		blocks.resize(b_size, 0);
		for (int i = 0; i<n; i++) {
			blocks[i / b_size] += num[i];
		}
	}

	void update(int i, int val) {
		blocks[i / b_size] = blocks[i / b_size] - num[i] + val;
		num[i] = val;
	}

	int sumRange(int i, int j) {
		int start_block = i / b_size;
		int end_block = j / b_size;
		int sum = 0;
		if (start_block == end_block) {
			for (int k = i; k <= j; k++)
				sum += num[k];
		}
		else {
			for (int k = i; k<(start_block + 1)*b_size; k++)
				sum += num[k];
			for (int k = start_block + 1; k <= end_block - 1; k++)
				sum += blocks[k];
			for (int k = end_block*b_size; k <= j; k++)
				sum += num[k];
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

//int main() {
//	vector<int>c{ 1,3,5 };
//	NumArray na(c);
//	na.sumRange(1, 2);
//}