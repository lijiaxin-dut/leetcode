#include<vector>

using namespace std;


//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., [0, 0, 1, 2, 2, 5, 6] might become[2, 5, 6, 0, 0, 1, 2]).
//
//You are given a target value to search.If found in the array return true, otherwise return false.
//
//Example 1:
//
//Input: nums = [2, 5, 6, 0, 0, 1, 2], target = 0
//	Output : true
//	Example 2 :
//
//	Input : nums = [2, 5, 6, 0, 0, 1, 2], target = 3
//	Output : false


//��midֵ���ұ�ֵ���ʱ���޷�ȷ����߻����ұ�
//ֻ����С�ұߵ��������Ѿ�ȷȷ��nums[right]��target�����
//����������ߵģ���ȷ����ߵ�������target�Ĺ�ϵ



class Solution_81 {
public:
	bool search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int mid = (right + left) / 2;
			if (nums[mid] == target)
				return true;
			//�Ұ벿����������
			if (nums[mid]<nums[right]) {
				//���Ұ�����
				if (nums[mid]<target&&nums[right] >= target)
					left = mid + 1;
				else
					right = mid - 1;
			}
			//��벿����������
			else if (nums[mid]>nums[right]) {
				//���������
				if (nums[mid]>target&&nums[left] <= target)
					right = mid - 1;
				else
					left = mid + 1;
			}
			else {
				right--;
			}
		}
		return false;

	}
};