#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:
//
//B.length >= 3
//There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i - 1] < B[i] > B[i + 1] > ... > B[B.length - 1]
//(Note that B could be any subarray of A, including the entire array A.)


//ʹ��˫ָ��ķ�����������濪ʼ��λ�ú����������λ��
//ע���±�ı仯

class Solution {
public:
	int longestMountain(vector<int>& A) {
		if (A.size() <= 2)
			return 0;
		//���濪ʼ��λ��
		int left = -1;
		//���������λ��
		int right = -1;
		int rs = 0;
		//��ǰ�жϵ�λ��
		int i = 0;
		while (i + 1<A.size()) {
			//��������ǲ�����ɽ��
			bool left_part = false;
			//��������ǲ�����ɽ��
			bool right_part = false;
			left = i;
			//�ҵ����������λ��
			while (i + 1<A.size() && A[i]<A[i + 1]) {
				left_part = true;
				i++;
			}
			//�ҵ����������λ��
			while (i + 1<A.size() && A[i]>A[i + 1]) {
				right_part = true;
				i++;
			}
			right = i;
			//������Ҷ���ɽ��
			if (left_part == true && right_part == true)
				rs = max(rs, right - left + 1);
			//�����ȫ��ƽ�ģ�����[1,1],i��Ҫ����
			else if (left_part == false && right_part == false)
				i++;
			//���ֻ�����棬�㷨���������ֻ�����棬i���䣬������while��λ�ÿ�ʼ�ж�
			else if (left_part == false || right_part == false)
				continue;
		}
		return rs;
	}
};