#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution_31 {
public:
	//����β�˿�ʼ�ң��ҵ�һ�������λ������i>i-1
	//��β�˿�ʼ�ң��ҳ���һ������i-1��Ԫ��
	//����i-1 j
	//i��end����
	void nextPermutation(vector<int>& nums) {
		if (nums.size() == 1)
			return;
		for (int i_1 = nums.size() - 2, i = nums.size() - 1; i_1 >= 0; i--, i_1--) {
			//�ҵ���һ�������λ�ã�i-1<i
			if (nums[i_1]<nums[i]) {
				for (int j = nums.size() - 1; j >= i - 1; j--) {
					//�ҵ���һ����i-1���λ��
					if (nums[j]>nums[i - 1]) {
						swap(nums[i - 1], nums[j]);
						//i����β����
						reverse(nums.begin() + i, nums.end());
						return;
					}
				}
			}
		}
		reverse(nums.begin(), nums.end());
		return;
	}
};