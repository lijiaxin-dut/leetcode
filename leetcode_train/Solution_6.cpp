#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of 
//rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R

//建立一个二维辅助数组
//不断的填入到数组中


class Solution_6 {
public:
	string convert(string s, int numRows) {

		int n = s.size();
		string rs;
		int col_number = n / (numRows * 2 - 2)*numRows + numRows;
		vector<vector<char>>map(numRows, vector<char>(col_number));
		int group_col = numRows - 1;
		int current_col = 0;
		int current_row = 0;
		int index = 0;
		while (true) {
			while (current_row<numRows&&index<n)
				map[current_row++][current_col] = s[index++];
			current_col++;
			current_row = current_row - 2;
			while (current_row>0 && index<n)
				map[current_row--][current_col++] = s[index++];
			if (index == n)
				break;
		}
		for (auto &one_row : map)
		{
			for (auto &one_char : one_row) {
				if(one_char!='\0')
					rs.push_back(one_char);
			}
				
		}
		return rs;
	}
};

//int main() {
//	Solution_6 s;
//	s.convert("PAYPALISHIRING", 3);
//}