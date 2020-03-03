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


//ʹ�ù鲢���򣬶����е�ǰ׺�ͽ�������

//��merge�Ĺ����У��ҵ���һ��sums[j]-sums[i]>=lower��λ��
//�ҵ���һ��sums[k]-sums[i]>upper��λ��
//k-j���Ƕ���i�Ľ��

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

	long rs = 0;
	vector<long>aux;
public:
	int countRangeSum_merge(vector<int>& nums, int lower, int upper) {
		int n = nums.size();
		if (n == 0)
			return 0;
		vector<long>sums(n + 1, 0);
		for (int i = 0; i<n; i++)
			sums[i + 1] = sums[i] + nums[i];
		aux.resize(n + 1, 0);
		merge(sums, 0, n, lower, upper);
		return rs;
	}
	void merge(vector<long>&sums, int left, int right, int l, int u) {
		if (left<right) {
			int mid = left + (right - left) / 2;
			merge(sums, left, mid, l, u);
			merge(sums, mid + 1, right, l, u);
			merge_help(sums, left, mid, right, l, u);
		}
	}
	void merge_help(vector<long>&sums, int left, int mid, int right, int l, int u) {
		int first_greater_equal_lower = mid + 1;
		int first_greater_upper = mid + 1;

		for (int i = left; i <= mid; i++) {
			while (first_greater_equal_lower <= right&&sums[first_greater_equal_lower] - sums[i]<l)
				first_greater_equal_lower++;
			while (first_greater_upper <= right&&sums[first_greater_upper] - sums[i] <= u)
				first_greater_upper++;
			rs += first_greater_upper - first_greater_equal_lower;
		}

		int i = left;
		int j = mid + 1;
		for (int cur_index = left; cur_index <= right; cur_index++) {
			if (i == mid + 1)
				aux[cur_index] = sums[j++];
			else if (j == right + 1)
				aux[cur_index] = sums[i++];
			else if (sums[i] <= sums[j])
				aux[cur_index] = sums[i++];
			else
				aux[cur_index] = sums[j++];
		}
		for (int i = left; i <= right; i++)
			sums[i] = aux[i];





	}
};