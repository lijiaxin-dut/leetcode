#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given an array of integers, 1 �� a[i] �� n(n = size of array), some elements appear twice and others appear once.
//
//Find all the elements that appear twice in this array.
//
//Could you do it without extra space and in O(n) runtime ?
//
//Example :
//	Input :
//	[4, 3, 2, 7, 8, 2, 3, 1]
//
//Output :
//	[2, 3]


//�ⷨ1��
//��Ŀ�޶���ÿһ��ֵ��ȡֵ��Χ�ڣ�
//ÿ����һ��i,��nums[nums[i]-1]��ֵȡ��
//����´�����j��nums[nums[j]-1]���Ѿ�Ϊ������˵��֮ǰ����������������漴��


class Solution_442 {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		int n = nums.size();
		vector<int>rs;
		for (int i = 0; i<n; i++) {
			//�ҵ���Ӧ������
			int index = abs(nums[i]) - 1;
			//С��0˵��֮ǰ���������ֵ
			if (nums[index]<0) {
				rs.push_back(index + 1);
			}
			//��ֵȡ��
			else {
				nums[index] = -nums[index];
			}
		}
		return rs;
	}
};