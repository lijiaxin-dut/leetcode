#include<unordered_set>
#include<vector>

using namespace std;

//Given a non - empty array of numbers, a0, a1, a2, ��, an - 1, where 0 �� ai < 231.
//
//	Find the maximum result of ai XOR aj, where 0 �� i, j < n.
//
//	Could you do this in O(n) runtime ?
//
//	Example :
//
//	Input : [3, 10, 5, 25, 2, 8]
//
//	Output : 28
//
//	Explanation : The maximum result is 5 ^ 25 = 28.



//��֪   a^b=x  �� a^x=b
//��λȷ��

//ÿһ�ν��������ֵ�ǰiλ���浽set��

//�����λΪ���ӣ������е����ֵ����λ�ŵ�һ��HashSet���棬
//Ȼ��ʹ��1��set������������ֽ������
//����ó��Ľ����Ȼ��set���棬��ô���ս�������λ��ȻΪ1������Ϊ0��

//����  �������λΪ1  1000  set����1000  0000
//1000^1000==0000  �������ȷ������λΪ1
//a^b=x  �� a^x=b


class Solution_421 {
public:
	int findMaximumXOR(vector<int>& nums) {
		int rs = 0;
		int mark = 0;
		for (int i = 31; i >= 0; i--) {
			mark = mark | (1 << i);
			unordered_set<int>hash_set;
			for (auto one_num : nums)
				hash_set.insert(one_num&mark);
			int t = rs | (1 << i);
			for (auto pre : hash_set) {
				if (hash_set.count(pre^t)) {
					rs = t;
					break;
				}
			}
		}
		return rs;
	}
};