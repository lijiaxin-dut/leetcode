#include<string>

using namespace std;

//Given an integer, return its base 7 string representation.
//
//Example 1:
//Input: 100
//	Output : "202"

class Solution {
public:
	string convertToBase7(int num) {
		if (num == 0)
			return "0";
		bool is_negative = false;
		if (num<0)
			is_negative = true;
		num = abs(num);
		string rs;
		while (num>0) {
			rs += to_string(num % 7);
			num = num / 7;
		}
		reverse(rs.begin(), rs.end());
		return is_negative == false ? rs : "-" + rs;



	}
};