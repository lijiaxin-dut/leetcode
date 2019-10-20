#include<vector>
#include<algorithm>
using namespace std;


//Given an unsorted array of integers, find the length of longest increasing subsequence.
//
//Example:
//
//Input: [10, 9, 2, 5, 3, 7, 101, 18]
//	Output : 4
//	Explanation : The longest increasing subsequence is[2, 3, 7, 101], therefore the length is 4.
//
//

//�����������
//ά��һ��һά dp ���飬���� dp[i] ��ʾ�� nums[i] Ϊ��β��������Ӵ��ĳ��ȣ�
//����ÿһ�� nums[i]���ӵ�һ������������i���������ĳ����С�� nums[i]��
//���� dp[i]�����·���Ϊ dp[i] = max(dp[i], dp[j] + 1)

class Solution_300 {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int n = nums.size();
		vector<int>dp(n, 1);
		int rs = 1;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<i; j++) {
				if (nums[i]>nums[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
					rs = max(rs, dp[i]);
				}
			}
		}
		return rs;

	}
};