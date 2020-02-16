#include<vector>
#include<set>
#include<set>

using namespace std;

//Given an integer array nums, return the number of range sums that lie in[lower, upper] inclusive.
//Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j(i �� j), inclusive.
//
//Note:
//A naive algorithm of O(n2) is trivial.You MUST do better than that.

//ʹ��multiset�������е����
//�õ�һ���µ����ʱ��ϣ���ҵ�һ�� old_sum
//lb<=sum-old_sum<=up
//->sum-ub=< old_sum <=sum-lb
//��Ҫ�����ж��ٸ�sum�����������
//lower_bound(sum - upper)  ���ص�һ��>=sum-upper ��λ��
//upper_bound(sum - lower)  ���ص�һ��>sum-lower  ��λ��
//����λ������ֵ���ҵ����ٸ�����������old_sum

//����0Ϊ�˿���sum[0,j]������������

class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		int n = nums.size();
		multiset<long long>sums;
		long long sum = 0;
		int rs = 0;
		sums.insert(0);
		for (int i = 0; i<n; i++) {
			sum += nums[i];
			rs += distance(sums.lower_bound(sum - upper), sums.upper_bound(sum - lower));
			sums.insert(sum);
		}
		return rs;
	}
};