#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//Given an array of integers A sorted in non-decreasing order, 
//return an array of the squares of each number, also in sorted non-decreasing order.


//��Ϊԭ�������򣬽������е������ֿ�����

class Solution_977 {
public:
	vector<int> sortedSquares(vector<int>& A) {
		//�ҵ���һ��Ϊ����������
		int first_positive_index = 0;
		while (first_positive_index<A.size() && A[first_positive_index]<0)
			first_positive_index++;
		//�ҵ����һ��Ϊ����������
		int last_negative_index = first_positive_index - 1;
		vector<int>rs(A.size());
		int t = 0;
		//�����������������������Լ������Ϻϲ��������������
		//ʹ��two pointer�����ϲ�������������
		while (first_positive_index<A.size() && last_negative_index >= 0) {
			if (A[first_positive_index] * A[first_positive_index] <= A[last_negative_index] * A[last_negative_index]) {
				rs[t++] = A[first_positive_index] * A[first_positive_index];
				first_positive_index++;
			}
			else {
				rs[t++] = A[last_negative_index] * A[last_negative_index];
				last_negative_index--;
			}

		}
		//����δ�жϵĵ�������
		while (first_positive_index<A.size()) {
			rs[t++] = A[first_positive_index] * A[first_positive_index];
			first_positive_index++;
		}
		while (last_negative_index >= 0) {
			rs[t++] = A[last_negative_index] * A[last_negative_index];
			last_negative_index--;
		}
		return rs;
	}
};

//int main() {
//	Solution_977 s;
//	vector<int>A{ -4 };
//	s.sortedSquares(A);
//}