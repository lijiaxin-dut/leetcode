#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


class Solution_581 {
public:
	//nums[i]<nums[i-1]ʱ����nums[i]��ǰ�ƶ������ʵ�λ�ã��������������
	//��¼��Զ���ƶ�λ��
	int findUnsortedSubarray(vector<int>& nums) {
		if (nums.size() <= 1)
			return 0;
		int rs = 0;
		int start = INT_MAX;
		for (int i = 1; i<nums.size(); i++) {
			if (nums[i]<nums[i - 1]) {
				int j = i;
				while (j>0 && nums[j]<nums[j - 1])
				{
					swap(nums[j], nums[j - 1]);
					j--;
				}
				if (j<start)
					start = j;
				rs = i - start + 1;
			}
		}
		return rs;
	}
	//ʹ����ʱ�ռ�������������
	//���αȽ����飬�ҵ���һ�µ���ʼλ�ã��������������
	int findUnsortedSubarray_2(vector<int>& nums) {
		vector<int>t = nums;
		sort(t.begin(), t.end());
		int left = 0;
		int right = nums.size() - 1;
		while (left < nums.size() && nums[left] == t[left])
			left++;
		while (right > left&&nums[right] == t[right])
			right--;
		return right - left + 1;
	}



	int findUnsortedSubarray_3(vector<int>& nums) {
		int n = nums.size();
		vector<int>maxlhs(n);// max number from left to cur
		vector<int>minrhs(n);// min number from right to cur
		int max_val = INT_MIN;
		for (int i = 0; i < n; i++) {
			max_val = max(nums[i], max_val);
			maxlhs[i] = max_val;

		}
		int min_val = INT_MAX;
		for (int i = n - 1; i >= 0; i--) {
			min_val = min(nums[i], min_val);
			minrhs[i] = min_val;
		}
		int i = 0, j = n - 1;
		//��ǰֵ���ұ���Сֵ��ҪС���Ѿ������ҵ������ұ���СֵС������
		while (i < n && nums[i] <= minrhs[i])
			i++;
		//��ǰֵ��������ֵ��Ҫ���Ѿ������ҵ�����������ֵ�������
		while (j > i && nums[j] >= maxlhs[j])
			j--;

		return j + 1 - i;
	}
};