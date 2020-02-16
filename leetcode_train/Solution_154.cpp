#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
#include<map>
using namespace std;

//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., [0, 1, 2, 4, 5, 6, 7] might become[4, 5, 6, 7, 0, 1, 2]).
//
//Find the minimum element.
//
//The array may contain duplicates.


//�������ʱ�����Ҳ�index--
//��������һ��

class Solution_154 {
public:
	int findMin(vector<int>& nums) {
		int n = nums.size();
		if (n == 1)
			return nums[0];
		int rs = nums[0];
		int left = 0;
		int right = n - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			//�Ұ벿������
			if (nums[mid]<nums[right]) {
				rs = min(rs, nums[mid]);
				right = mid - 1;
			}
			else if (nums[mid]>nums[left]) {
				rs = min(rs, nums[left]);
				left = mid + 1;
			}
			else {
				rs = min(rs, nums[right]);
				right--;
			}
		}
		return rs;
	}
};