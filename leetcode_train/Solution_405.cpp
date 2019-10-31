#include<vector>
#include<string>

using namespace std;

//
//Given an integer, write an algorithm to convert it to hexadecimal.For negative integer, two’s complement method is used.
//
//Note:
//
//All letters in hexadecimal(a - f) must be in lowercase.
//The hexadecimal string must not contain extra leading 0s.If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
//The given number is guaranteed to fit within the range of a 32 - bit signed integer.
//You must not use any method provided by the library which converts / formats the number to hex directly.

//每次右移四位

class Solution_405 {
public:
	string toHex(int num) {
		vector<string>map{ "0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f" };
		string rs;
		for (int i = 0; i<8; i++) {
			int temp = num & 0x0000000f;
			rs += map[temp];
			num = num >> 4;
		}
		while (!rs.empty() && rs.back() == '0')
			rs.pop_back();
		reverse(rs.begin(), rs.end());
		return rs.empty() ? "0" : rs;

	}
};