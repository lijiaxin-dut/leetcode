#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

//Given an array of integers and an integer k, you need to find the number of unique k - diff pairs 
//in the array.Here a k - diff pair is defined as an integer pair(i, j), where i and j are both 
//numbers in the array and their absolute difference is k.

//Note:
//The pairs(i, j) and (j, i) count as the same pair.

//1.ע�������ظ���Ԫ��
//ʹ������ָ�룬�Ƚ�����ָ��Ĳ�ֵ������ָ���ƶ�
//2.ͳ��������ÿ��Ԫ�صĸ�����ʹ��unordered_map
//����ÿһ����num�����k+numҲ�������У���+1
//���k==0,��ônum�ĵĴ������>1,Ҳ��1


class Solution_532 {
	int findPairs_one_pass(vector<int>& nums, int k) {
		unordered_map<int, int>s;
		for (auto &one_num : nums)
			s[one_num]++;
		int rs = 0;
		for (auto &one_pair : s) {
			if (k>0 && s.count(one_pair.first + k))
				rs++;
			if (k == 0 && s[one_pair.first + k]>1)
				rs++;
		}
		return rs;


	}
public:
	int findPairs(vector<int>& nums, int k) {
		if (nums.size() <= 1) {
			return 0;
		}
		int rs = 0;
		//���ȶ������������
		sort(nums.begin(), nums.end());
		int first = 1; int second = 0;
		//������¼��һ����λ��λ��
		int last_first = INT_MAX;
		while (first<nums.size()) {
			if (abs(nums[second] - nums[first]) == k) {
				second++;
				//�����ȣ���˵�����pair���ֹ�
				if (last_first != nums[second]) {
					last_first = nums[second];
					rs++;
				}
			}
			else if (abs(nums[first] - nums[second])<k) {
				first++;
			}
			else if (abs(nums[first] - nums[second])>k) {
				second++;
			}
			if (first == second)
				first++;
		}
		return rs;
	}
};

//int main() {
//	Solution_532 s;
//	vector<int>nums{ 11,3,1,5,4};
//	s.findPairs(nums, 0);
//}