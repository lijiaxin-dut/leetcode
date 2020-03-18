#include<vector>
#include<algorithm>

using namespace std;

//Given two arrays of length m and n with digits 0 - 9 representing two numbers.Create the maximum number of length k <= m + n from digits of the two.The relative order of the digits from the same array must be preserved.Return an array of the k digits.
//
//Note: You should try to optimize your time and space complexity.
//
//	Example 1 :
//
//	Input :
//	nums1 = [3, 4, 6, 5]
//	nums2 = [9, 1, 2, 5, 8, 3]
//	k = 5
//	Output :
//	[9, 8, 6, 5, 3]
//Example 2 :
//
//	Input :
//	nums1 = [6, 7]
//	nums2 = [6, 0, 4]
//	k = 5
//	Output :
//	[6, 7, 6, 0, 4]

//���������������������
//sub1
//��nums����k���������������������ջ

//sub2
//��nums1��nums2�У��ҵ����ɵ�������
//�Ƚ�����
//ÿ�η��ؽϴ�����ĵ�һ��Ԫ��
//lexicographical(s1,e1,s2,e2)�����һ��Ԫ��С������true


//������
//������еĿ����ԣ��ӵ�һ��������ѡi�����ӵڶ���������ѡk-i��




class Solution {
	vector<int> max_number(const vector<int>&nums, int k) {
		vector<int>s;
		int n = nums.size();
		int delete_number = 0;
		for (int i = 0; i<n; i++) {
			while (!s.empty() && nums[i]>s.back() && delete_number<n - k) {
				s.pop_back();
				delete_number++;
			}
			s.push_back(nums[i]);
		}
		s.resize(k);
		return s;
	}
	vector<int> max_number(const vector<int>& nums1, const vector<int>& nums2) {
		vector<int>rs(nums1.size() + nums2.size());
		auto s1 = nums1.begin();
		auto e1 = nums1.end();
		auto s2 = nums2.begin();
		auto e2 = nums2.end();
		int cur_index = 0;
		while (s1 != e1 || s2 != e2) {
			rs[cur_index++] = lexicographical_compare(s1, e1, s2, e2) ? *s2++ : *s1++;
		}
		return rs;
	}
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> ans;
		int n1 = nums1.size();
		int n2 = nums2.size();
		for (int k1 = 0; k1 <= k; k1++) {
			int k2 = k - k1;
			if (k1>n1 || k2>n2)
				continue;
			ans = max(ans, max_number(max_number(nums1, k1), max_number(nums2, k2)));
		}
		return ans;

	}
};