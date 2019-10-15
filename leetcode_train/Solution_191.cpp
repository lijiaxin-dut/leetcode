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

//���ϵĽ�n�����ƶ����ж����һλ�Ƿ�λ1����


//���߽�n�����һ��1ȥ����
//Ȼ��n&(n-1)
//ֱ��Ϊ0����


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