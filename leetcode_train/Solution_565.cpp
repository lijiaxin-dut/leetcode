#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//A zero - indexed array A of length N contains all integers from 0 to N - 1. Find and return the longest length of set S, where S[i] = { A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.
//
//Suppose the first element in S starts with the selection of element A[i] of index = i, the next element in S should be A[A[i]], and then A[A[A[i]]]… By that analogy, we stop adding right before a duplicate element occurs in S.

//当循环出现的时候，嵌套数组的长度也不能再增加了，而出现的这个相同的数一定是嵌套数组的首元素
//标记出现过的位置，下一次迭代跳过即可

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