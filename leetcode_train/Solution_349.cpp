#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//Description
//Given two arrays, write a function to compute their intersection.
//�����ÿ������Ψһ

class Solution_349 {
public:

	//������ʹ����ʱ�ռ���
	vector<int> intersection_no_sort(vector<int>& nums1, vector<int>& nums2) {
		set<int>rs;
		set<int>mark;
		for (int i = 0; i<nums1.size(); i++)
			mark.insert(nums1[i]);
		for (auto i : nums2) {
			if (mark.find(i) != mark.end())
				rs.insert(i);
		}
		return{ rs.begin(),rs.end() };
	}

	//Ԥ�����򣬲�ʹ����ʱ�ռ�
	vector<int> intersection_sort(vector<int>& nums1, vector<int>& nums2) {
		set<int>rs;
		int nums1_index = 0;
		int nums2_index = 0;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		while (nums1_index<nums1.size() && nums2_index<nums2.size()) {
			if (nums1[nums1_index] == nums2[nums2_index]) {
				rs.insert(nums1[nums1_index]);
				nums1_index++;
				nums2_index++;
			}
			else if (nums1[nums1_index]>nums2[nums2_index])
				nums2_index++;
			else
				nums1_index++;

		}
		return{ rs.begin(),rs.end() };
	}

};