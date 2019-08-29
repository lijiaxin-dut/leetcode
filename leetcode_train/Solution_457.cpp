#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

//You are given a circular array nums of positive and negative integers. 
//If a number k at an index is positive, then move forward k steps. 
//Conversely, if it's negative (-k), move backward k steps. Since the array is circular, 
//you may assume that the last element's next element is the first element, 
//and the first element's previous element is the last element.

//Determine if there is a loop(or a cycle) in nums.A cycle must start and end at the same index and 
//the cycle's length > 1. Furthermore, movements in a cycle must all follow a single direction. 
//In other words, a cycle must not consist of both forward and backward movements.


class Solution_457 {
public:
	bool circularArrayLoop(vector<int>& nums) {
		int n = nums.size();
		vector<bool>global_mark(n, 0);
		for (int i = 0; i<nums.size(); i++) {
			//��Ǳ����г��ֵ�index
			set<int>index;
			int start_index = i;
			if (global_mark[start_index] == 1)
				continue;
			index.insert(start_index);
			global_mark[start_index] = 1;
			while (true) {
				int step = nums[start_index];
				//����������ѭ��,ֵ�����������ı��������߷��Ų�һ�µĵ�
				if (abs(step) % n == 0 || (step>0 && nums[i]<0) || (step<0 && nums[i]>0))
					break;
				start_index = (start_index + step) % n;
				if (start_index<0)
					start_index = start_index + n;
				//���index���ֹ����ҳ���>1
				if (index.find(start_index) != index.end())
					return true;
				//���indexû�г��ֹ������б��
				else
					index.insert(start_index);
				//�����������index
				global_mark[start_index] = 1;
				if (index.size()>n)
					break;

			}
		}
		return false;
	}
};

//int main() {
//	Solution_457 s;
//	vector<int>nums{1,1 };
//	s.circularArrayLoop(nums);
//}