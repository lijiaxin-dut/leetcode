#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Write a function that reverses a string.The input string is given as an array of characters char[].

//Do not allocate extra space for another array, you must do this by modifying the input array 
//in - place with O(1) extra memory.

class Solution_344 {
public:
	void reverseString(vector<char>& s) {
		int lo = 0, hi = s.size() - 1;
		while (lo<hi) {
			swap(s[lo], s[hi]);
			lo++;
			hi--;
		}
	}
};