#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//����1 bfs
//����һ������ʱ���ݹ��ѯ���еĿ�����

//����2 ̰��
//ʹ��reach���鱣�ֵ�ǰ��Զ�Ĳ���
//��ǰ��һ��ʱ��reach--
class Solution_55 {
public:
	bool canJump(vector<int>& nums) {
		bool can_jp = false;
		help(nums, 0, can_jp);
		return can_jp;
	}
	void help(vector<int>&nums, int start_index, bool &can_jp) {
		if (start_index == nums.size() - 1)
			can_jp = true;
		if (nums[start_index] == 0 || can_jp == true)
			return;	
		for (int i = start_index + 1; i<nums.size() && i <= start_index + nums[start_index]; i++) {
			help(nums, i, can_jp);
		}
	}

	bool canJump_1(vector<int>& nums) {
		if (nums.size() <= 1)
			return true;
		int reach = 0;
		for (int i = 0; i<nums.size(); i++) {
			reach = max(reach, nums[i]);
			if (reach <= 0 && i != nums.size() - 1)
				return false;
			reach--;
		}
		return true;
	}


};
//int main() {
//	vector<int>matrix{ 2,0 };
//	Solution_55 s;
//	s.canJump(matrix);
//}