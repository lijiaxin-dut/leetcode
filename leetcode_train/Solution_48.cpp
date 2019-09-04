#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//You are given an n x n 2D matrix representing an image.
//
//Rotate the image by 90 degrees(clockwise).
//
//Note:
//
//You have to rotate the image in - place, which means you have to modify the input 
//2D matrix directly.DO NOT allocate another 2D matrix and do the rotation.


//�������ŶԽ��߽��з�ת
//Ȼ������y����з�ת
//���ŶԽ��߷�תʱ��ע������ı任

class Solution_48 {
public:

	void rotate(vector<vector<int>>& matrix) {
		int  n = matrix.size();
		for (int i = 0; i<n - 1; i++) {
			for (int j = 0; j<n - i - 1; j++) {
				swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
			}
		}
		for (int i = 0; i<n / 2; i++) {
			for (int j = 0; j<n; j++) {
				swap(matrix[i][j], matrix[n - i - 1][j]);
			}
		}
	}
};