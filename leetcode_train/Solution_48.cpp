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



/*
* clockwise rotate
* first reverse up to down, then swap the symmetry
* 1 2 3     7 8 9     7 4 1
* 4 5 6  => 4 5 6  => 8 5 2
* 7 8 9     1 2 3     9 6 3
*/
class Solution_48 {
public:

	void rotate(vector<vector<int> > &matrix) {
		reverse(matrix.begin(), matrix.end());

		//¾µÏñÐý×ª
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = i + 1; j < matrix[i].size(); ++j)
				swap(matrix[i][j], matrix[j][i]);
		}
	}


	/*
	* anticlockwise rotate
	* first reverse left to right, then swap the symmetry
	* 1 2 3     3 2 1     3 6 9
	* 4 5 6  => 6 5 4  => 2 5 8
	* 7 8 9     9 8 7     1 4 7
	*/
	void anti_rotate(vector<vector<int> > &matrix) {
		for (auto vi : matrix) reverse(vi.begin(), vi.end());
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = i + 1; j < matrix[i].size(); ++j)
				swap(matrix[i][j], matrix[j][i]);
		}
	}

};