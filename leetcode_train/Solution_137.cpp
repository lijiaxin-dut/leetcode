#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

//Given a non - empty array of integers, every element appears three times except for one, 
//which appears exactly once.Find that single one.
//
//Note:
//
//Your algorithm should have a linear runtime complexity.
//Could you implement it without using extra memory ?
//

//ÿһ�����ֹ�32λ��ͳ��ÿһλ���ֵ�һ�ĸ���
//sum += (nums[j] >> i) & 1;

//���ĳһλ��Ϊ1�Ļ�����ô������������������Σ���3ȡ��Ϊ0��
//������ÿ�����Ķ�Ӧλ����������3ȡ�࣬����ʣ�������Ǹ������ǵ���������

class Solution_137 {
public:
	int singleNumber(vector<int>& nums) {

		int res = 0;
		for (int i = 0; i<32; i++) {
			int sum = 0;
			for (int j = 0; j<nums.size(); j++) {
				sum += (nums[j] >> i) & 1;
			}
			res |= (sum % 3) << i;
		}
		return res;

	}
};