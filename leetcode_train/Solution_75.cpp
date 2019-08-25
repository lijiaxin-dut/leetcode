#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Description

//Given an array with n objects colored red, white or blue, sort them in - place so that objects of 
//the same color are adjacent, with the colors in the order red, white and blue.
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//Note: You are not suppose to use the library's sort function for this problem.


//ʹ��������������λ�õ�������ʾ0���Է��õ�λ�ã���λ�õ�������ʾ2���Է��õ�λ�ã���¼�Ѿ����úõ�2�ĸ�����
//������ǰ����ѭ��

class Solution_75 {
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() <= 1)
			return;
		int hi = nums.size() - 1;
		int lo = 0;
		int hi_size = 0;
		for (int i = 0; i<nums.size() - hi_size; i++)
		{
			//���ʱ2���ŵ���λ��
			if (nums[i] == 2)
			{
				swap(nums[i], nums[hi--]);
				hi_size++;
				//������ǰλ�ÿ�����0��������1����Ҫ�����ж�
				i--;
			}
			//���ʱ0���ŵ���λ��
			//������ǰλ��һ��ʱ0
			else if (nums[i] == 0)
			{
				swap(nums[i], nums[lo++]);
			}
		}

	}
};
//int main() {
//	Solution_75 s;
//	vector<int>color{ 2};
//	s.sortColors(color);
//}