#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

//Note that the row index starts from 0.

//Example:
//
//Input: 3
//	Output : [1, 3, 3, 1]
//	Follow up :
//
//	   Could you optimize your algorithm to use only O(k) extra space ?


//用一个临时变脸保存前一行的结果就行

class Solution_106 {
public:
	vector<int> getRow(int rowIndex) {
		vector<int>temp(rowIndex + 1);
		vector<int>rs(rowIndex + 1);
		for (int i = 0; i <= rowIndex; i++) {
			for (int j = 0; j <= i; j++) {
				if (i == 0 || j == 0 || j == i) {
					temp[j] = 1;
				}
				else {
					temp[j] = rs[j] + rs[j - 1];
				}
			}
			for (int k = 0; k <= i; k++) {
				rs[k] = temp[k];
			}
		}
		return rs;

	}
};