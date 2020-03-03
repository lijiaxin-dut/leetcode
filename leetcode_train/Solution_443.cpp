#include<vector>
#include<string>
using namespace std;

//Given an array of characters, compress it in - place.
//
//The length after compression must always be smaller than or equal to the original array.
//
//Every element of the array should be a character(not int) of length 1.
//
//After you are done modifying the input array in - place, return the new length of the array.

//在计数时，没有考虑a1的情况，所以直接覆盖即可

class Solution {
public:
	int compress(vector<char>& chars) {
		int n = chars.size();
		int cur = 0;
		for (int i = 0, j = 0; i < n; i = j) {
			while (j < n && chars[j] == chars[i])
				++j;
			chars[cur++] = chars[i];
			if (j - i == 1)
				continue;
			for (char c : to_string(j - i))
				chars[cur++] = c;
		}
		return cur;
	}
};