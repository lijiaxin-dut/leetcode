#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//Description
//Given two arrays, write a function to compute their intersection.
//Each element in the result should appear as many times as it shows in both arrays.
//�����Ψһ�����Ƕ�γ��ֵ�����

//�������һ������ܴ���һ�������С������ʹ��binary search

//���һ������ܴ��޷������ڴ���
//���Ƚ��ڴ�С���������hash_map
//������ݺܴ󣬲���һ�η����ڴ棬�Ź�������ڴ��У�ÿ�ζ���һС��

//If both nums1 and nums2 are so huge that neither fit into the memory, sort them individually (external sort), 
//then read 2 elements from each array at a time in memory, record intersections.

class Solution_350 {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int>rs;
		int nums1_index = 0;
		int nums2_index = 0;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		while (nums1_index<nums1.size() && nums2_index<nums2.size()) {
			if (nums1[nums1_index] == nums2[nums2_index]) {
				rs.push_back(nums1[nums1_index]);
				nums1_index++;
				nums2_index++;
			}
			else if (nums1[nums1_index]>nums2[nums2_index])
				nums2_index++;
			else
				nums1_index++;

		}
		return rs;
	}
};