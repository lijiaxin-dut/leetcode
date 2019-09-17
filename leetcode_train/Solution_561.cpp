#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given an array of 2n integers, your task is to group these integers into n pairs of integer, say(a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
//
//Example 1:
//Input: [1, 4, 3, 2]
//
//	Output : 4
//	Explanation : n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).

//Ҫ���ÿ���еĽ�Сֵ֮�ͣ���ô�϶���ÿ�����������ִ�СԽ�ӽ�Խ�ã���Ϊ���������
//������ֻȡ��С�����֣���ô�����־��˷ѵ���

//���ȶ��������򣬰�˳���ÿ��������һ�ԣ�����ȡ��ÿ���еĵ�һ������Ϊ��Сֵ�ۼ���������


class Solution_561{
public:
	int arrayPairSum(vector<int>& nums) {
		int two_n = nums.size();
		int n = nums.size() / 2;
		sort(nums.begin(), nums.end());
		int rs = 0;
		for (int i = 0; i<two_n; i = i + 2) {
			rs += nums[i];
		}
		return rs;
	}
};