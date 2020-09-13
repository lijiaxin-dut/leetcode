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

//把这个问题拆成两个子问题
//sub1
//在nums中找k个数，构成最大数，单调栈

//sub2
//在nums1和nums2中，找到构成的最大大数
//比较数组
//每次返回较大数组的第一个元素
//lexicographical(s1,e1,s2,e2)如果第一个元素小，返回true


//主问题
//穷举所有的可能性，从第一个数组中选i个，从第二个数组中选k-i个




class Solution {

	vector<int>max_number_in_one_vector(const vector<int>&nums, int k) {
		vector<int>rs;
		int n = nums.size();
		int delete_number = 0;
		for (int i = 0; i<n; i++) {
			while (!rs.empty() && rs.back()<nums[i] && delete_number<n - k) {
				rs.pop_back();
				delete_number++;
			}
			rs.push_back(nums[i]);
		}
		rs.resize(k);
		return rs;
	}

	vector<int>max_number_in_two_vector(const vector<int>&num1, const vector<int>&num2) {
		vector<int>rs(num1.size() + num2.size(), 0);
		auto s1 = num1.begin();
		auto s2 = num2.begin();
		auto e1 = num1.end();
		auto e2 = num2.end();
		int cur_index = 0;
		while (s1 != e1 || s2 != e2) {
			rs[cur_index++] = lexicographical_compare(s1, e1, s2, e2) ? *s2++ : *s1++;
		}
		return rs;
	}



public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int>rs;
		int n1 = nums1.size();
		int n2 = nums2.size();
		for (int k1 = 0; k1 <= k; k1++) {
			int k2 = k - k1;
			if (k1>n1 || k2>n2)
				continue;
			rs = max(rs, max_number_in_two_vector(max_number_in_one_vector(nums1, k1), max_number_in_one_vector(nums2, k2)));
		}
		return rs;


	}
};