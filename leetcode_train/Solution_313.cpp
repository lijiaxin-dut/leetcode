#include<vector>

using namespace std;

//Write a program to find the nth super ugly number.
//
//Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.
//
//Example:
//
//Input: n = 12, primes = [2, 7, 13, 19]
//	Output : 32
//	Explanation : [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12
//	super ugly numbers given primes = [2, 7, 13, 19] of size 4.


//按顺序生成ugly number
//记录*prime[i]在已经生成的ugly中的索引



//注意去重，可能有多种方式得到下一个数字



class Solution_313 {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		int prime_size = primes.size();
		vector<int>prime_index(prime_size, 0);
		vector<int>nums{ 1 };
		while (nums.size()<n) {
			int min_value = INT_MAX;
			int min_value_index = -1;
			for (int i = 0; i<prime_size; i++) {
				if (nums[prime_index[i]] * primes[i]<min_value) {
					min_value = nums[prime_index[i]] * primes[i];
					min_value_index = i;
				}
			}
			//cout<<nums.back()<<"\t"<<min_value<<endl;
			if (nums.back() != min_value)
				nums.push_back(min_value);
			prime_index[min_value_index]++;
		}
		return nums.back();
	}
};