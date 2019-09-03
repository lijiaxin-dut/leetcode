#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., [0, 1, 2, 4, 5, 6, 7] might become[4, 5, 6, 7, 0, 1, 2]).
//
//You are given a target value to search.If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//0����1����2���� 4����5����6����7
//
//7����0����1���� 2����4����5����6
//
//6����7����0���� 1����2����4����5
//
//5����6����7���� 0����1����2����4
//
//4����5����6����7����0����1����2
//
//2����4����5����6����7����0����1
//
//1����2����4����5����6����7����0

//�����������Ĺؼ����ڻ�����м������ж�����Ҫ�������λ����Ұ�Σ�
//���ǹ۲������ɫ�����ֶ�������ģ��ɴ����ǿ��Թ۲�����ɣ�
//����м����С�����ұߵ��������Ұ��������ģ�
//���м����������ұ������������������
//�ж�target�Ƿ�������������ڣ����˵�ֵ���бȽ�



class Solution_33 {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int mid = (right + left) / 2;
			if (nums[mid] == target)
				return mid;
			//�Ұ벿����������
			if (nums[mid]<nums[right]) {
				if (nums[mid]<target&&nums[right] >= target)
					left = mid + 1;
				else
					right = mid - 1;
			}
			//��벿����������
			else {
				if (nums[mid]>target&&nums[left] <= target)
					right = mid - 1;
				else
					left = mid + 1;
			}
		}
		return -1;

	}
};