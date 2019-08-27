#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
// prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
// find the duplicate one.


class Solution_287 {
public:
	int findDuplicate_binary_search(vector<int>& nums) {
		//һ��ֻ��n�����֣�����һ����k������<=k��Ԫ�صĸ���
		//����Сk����count(<=k)>k  ��k�����ظ���Ԫ��
		int min = 1;
		int max = nums.size() - 1;//����n��Ԫ��
		while (min<max) {
			int mid = (max + min) / 2;
			int count = 0;
			for (int i = 0; i<nums.size(); i++) {
				if (nums[i] <= mid)
					count++;
			}
			//midһ�������ظ�������
			if (count <= mid)
				min = mid + 1;
			//mid�������ظ������飬��Ҫ����mid
			else
				max = mid;
		}
		return min;
	}
	int findDuplicate(vector<int>& nums) {
		//����ָ��
		//������ÿ��Ԫ�����������ԣ�index��value,value��Ϊָ�룬ָ������λ��

		//���ظ�����ʱ��������Ϊ�����д��ڻ��������������ظ�������
		//�������� A = [2, 6, 4, 1, 3, 1, 5]
		//	index 0, 1, 2, 3, 4, 5, 6
		//	value:2, 6, 4, 1, 3, 1, 5
		//	������ʲô�� ������ָ������λ�� / ƫ����
		//	��ôvalue ��ʲô�� ��һ��λ�õĵ�ַ
		//	��ô�������Ϳ���ת��Ϊ : 0 - > 2 - > 4 -> 3 -> 1 -> 6 -> 5->
		//  [1 - >6-> 5 ->1 ����] ���Կ��������һ���л�������
		int fast = 0;
		int slow = 0;
		do {
			fast = nums[nums[fast]];
			slow = nums[slow];
		} while (fast != slow);
		fast = 0;
		while (fast != slow) {
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}
};