#include<iostream>

//Write a function that takes an unsigned integer and return the number of '1' bits it has(also known as the Hamming weight).
//
//
//
//Example 1:
//
//Input: 00000000000000000000000000001011
//	Output : 3
//	Explanation : The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
//

//不断的将n向右移动，判断最后一位是否位1即可


//或者将n的最后一个1去掉，
//然后n&(n-1)
//直至为0即可


class Solution_191 {
public:
	int hammingWeight(uint32_t n) {
		int rs = 0;
		// for(int i=0;i<32;i++){
		//     if(n&1==1)
		//         rs++;
		//     n=n>>1;
		// }
		while (n != 0) {
			rs++;
			n = (n - 1)&n;
		}
		return rs;

	}
};