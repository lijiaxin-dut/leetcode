
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;



class Solution_415 {
public:
	string addStrings(string num1, string num2) {
		int n1 = num1.size();
		int n2 = num2.size();
		if (n1 == 0)
			return num2;
		if (n2 == 0)
			return num1;
		int index_1 = n1 - 1;
		int index_2 = n2 - 1;
		int carry = 0;
		string rs;
		while (index_1 >= 0 || index_2 >= 0 || carry>0) {
			int x = index_1 >= 0 ? num1[index_1] - '0' : 0;
			int y = index_2 >= 0 ? num2[index_2] - '0' : 0;
			int num = x + y + carry;
			carry = num / 10;
			num = num % 10;
			rs.push_back(num + '0');
			index_1--;
			index_2--;
		}
		reverse(rs.begin(), rs.end());
		return rs;
	}
};

//int main() {
//	Solution_415 s;
//	s.addStrings("1234", "2");
//}