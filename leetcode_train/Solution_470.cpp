
#include<vector>

// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7
//
//Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.
//
//Do NOT use system's Math.random().



//Ëæ»úÉú³É0-49
//7*(a-1)+b-1

class Solution {
public:
	int rand10() {
		int val = INT_MAX;
		while (val >= 40) {
			val = 7 * (rand7() - 1) + (rand7() - 1);
		}
		return val % 10 + 1;

	}
};