#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>


using namespace std;
//
//Given a collection of distinct integers, return all possible permutations.
//
//Example:
//
//Input: [1, 2, 3]
//	Output :
//	[
//		[1, 2, 3],
//		[1, 3, 2],
//		[2, 1, 3],
//		[2, 3, 1],
//		[3, 1, 2],
//		[3, 2, 1]
//	]
//

//��ͣ�ĵ���next_permutation
//����ѭ����ֹͣ
//next_permutation
//�ҵ���һ������λ�� i-1<i
//�ҵ���һ������i-1��λ��j
//swap(i-1,j)
//i��end����


//dfs������еĿ����ԣ�ʹ�ñ�������¼�Ѿ����ʹ���λ��

class Solution_46 {
	void next_permutation(vector<int>&nums) {
		int n = nums.size();
		if (n == 0)
			return;
		for (int i = n - 1; i >= 1; i--) {
			if (nums[i - 1]<nums[i]) {
				for (int j = n - 1; j >= i; j--) {
					if (nums[j]>nums[i - 1])
					{
						swap(nums[j], nums[i - 1]);
						reverse(nums.begin() + i, nums.end());
						return;
					}
				}

			}
		}
		reverse(nums.begin(), nums.end());
	}
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>>rs;
		rs.push_back(nums);
		while (true){
			next_permutation(nums);
			if (nums != rs.front())
				rs.push_back(nums);
			else
				break;
		}
		return rs;
	}
};