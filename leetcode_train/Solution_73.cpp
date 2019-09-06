#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in - place.
//
//Example 1:
//
//Input:
//[
//	[1, 1, 1],
//	[1, 0, 1],
//	[1, 1, 1]
//]
//Output :
//	[
//		[1, 0, 1],
//		[0, 0, 0],
//		[1, 0, 1]
//	]

//ʹ�ö����һ�к�һ�б�ǳ���0���к���
//���ɨ�����飬���ݱ������


//����ʹ�õ�һ�к͵�һ����Ϊ���
//ʹ������flag��ǵ�һ�к͵�һ���Ƿ����0
//Ȼ��ʹ�õ�һ�к͵�һ�б��
//��������ݱ��λ���ж��Ƿ񽫵�һ�С���һ������



class Solution_73 {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<int>row(m, -1);
		vector<int>col(n, -1);
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (matrix[i][j] == 0) {
					row[i] = i;
					col[j] = j;
				}
			}
		}
		for (int i = 0; i<m; i++) {
			if (row[i] != -1) {
				for (int j = 0; j<n; j++) {
					matrix[i][j] = 0;
				}
			}
		}
		for (int j = 0; j<n; j++) {
			if (col[j] != -1) {
				for (int i = 0; i<m; i++) {
					matrix[i][j] = 0;
				}
			}
		}
	}
};