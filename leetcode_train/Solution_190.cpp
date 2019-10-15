#include<iostream>

//
//Reverse bits of a given 32 bits unsigned integer.
//
//
//
//Example 1:
//
//Input: 00000010100101000001111010011100
//	Output : 00111001011110000010100101000000
//	Explanation : The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
//	Example 2 :
//
//	Input : 11111111111111111111111111111101
//	Output : 10111111111111111111111111111111
//	Explanation : The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10101111110010110010011101101001.

	

//不断的从n中取出末尾的数字 n&1
//n&1==1
//则re<<一位并且+1
//否则rs<<一位即可

//n不断右移，一共32位，移动32次即可
	
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t rs = 0;
		for (int i = 0; i<32; i++) {
			if (n & 1 == 1) {
				rs = (rs << 1) + 1;
			}
			else {
				rs = rs << 1;
			}
			n = n >> 1;
		}
		return rs;
	}
};