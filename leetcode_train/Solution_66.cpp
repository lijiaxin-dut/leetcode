#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;
//
//Given a non - empty array of digits representing a non - negative integer, plus one to the integer.
//
//The digits are stored such that the most significant digit is at the head of the list, and each 
//element in the array contain a single digit.
//
//You may assume the integer does not contain any leading zero, except the number 0 itself.

//处理进位
//注意最后一位，+1后可能会多出一位，注意处理


class Solution_66 {
public:
	vector<int> plusOne(vector<int>& digits) {
		if (digits.size() <= 0)
			return digits;
		int index = digits.size() - 1;
		digits[index] += 1;
		int carry = digits[index] / 10;
		digits[index] %= 10;
		index--;
		while (index >= 0 && carry>0) {
			digits[index] += carry;
			carry = digits[index] / 10;
			digits[index] %= 10;
			index--;
		}
		if (carry>0)
			digits.insert(digits.begin(), carry);
		return digits;
	}
};