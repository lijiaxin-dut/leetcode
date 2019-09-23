#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>


using namespace std;


//Given two non - negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//
//Example 1:
//
//Input: num1 = "2", num2 = "3"
//	Output : "6"
//	Example 2 :
//
//	Input : num1 = "123", num2 = "456"
//	Output : "56088"
//

//注意进位
//每次需要加上进位
//i,j对应的乘积和为i+j+1
//进位的位置为i+j+1-1=i+j
//返回结果时，注意忽略前导0

class Solution_43 {
public:
	string multiply(string num1, string num2) {
		if (num1.empty())
			return num2;
		if (num2.empty())
			return num1;
		int n = num1.size();
		int m = num2.size();
		vector<int>rs(m + n, 0);
		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				int lhs = num1[i] - '0';
				int rhs = num2[j] - '0';
				int mult = lhs*rhs;
				rs[i + j + 1] = mult + rs[i + j + 1];
				rs[i + j] = rs[i + j] + rs[i + j + 1] / 10;
				rs[i + j + 1] = rs[i + j + 1] % 10;
			}
		}
		string s_rs;
		for (int i = 0; i < rs.size(); i++) {
			//找到第一个非0元素
			if (s_rs.size() || rs[i])
				s_rs.push_back(rs[i] + '0');
		}
		if (s_rs.empty())
			return "0";
		return s_rs;
	}
};

//int main() {
//	Solution_43 s;
//	cout<<s.multiply("123", "456");
//}
