#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//A zero - indexed array A of length N contains all integers from 0 to N - 1. Find and return the longest length of set S, where S[i] = { A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.
//
//Suppose the first element in S starts with the selection of element A[i] of index = i, the next element in S should be A[A[i]], and then A[A[A[i]]]�� By that analogy, we stop adding right before a duplicate element occurs in S.

//��ѭ�����ֵ�ʱ��Ƕ������ĳ���Ҳ�����������ˣ������ֵ������ͬ����һ����Ƕ���������Ԫ��
//��ǳ��ֹ���λ�ã���һ�ε�����������

class Solution_565 {
public:
	int arrayNesting(vector<int>& nums) {
		int rs = 0;
		int n = nums.size();
		vector<bool>mark(n, false);
		for (int i = 0; i<n; i++) {
			if (mark[nums[i]] == true) {
				continue;
			}
			int j = i;
			int count = 0;
			while (mark[nums[j]] == false)
			{
				count++;
				mark[nums[j]] = true;
				j = nums[j];
			}
			rs = max(rs, count);
		}
		return rs;
	}
};