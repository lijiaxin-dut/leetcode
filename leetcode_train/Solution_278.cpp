


//Suppose you have n versions[1, 2, ..., n] and you 
//want to find out the first bad one, which causes all the following ones to be bad.


//二分法找到第一个满足条件的数目
//注意终止条件
//lo<hi

//不确定终止条件时，举一个长度位2的例子，判断一下即可

bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int lo = 1;
		int hi = n;
		while (lo<hi) {
			int mid = lo + (hi - lo) / 2;
			bool temp = isBadVersion(mid);
			if (temp == true) {
				hi = mid;
			}
			else if (temp == false) {
				lo = mid + 1;
			}
		}
		return lo;

	}
};