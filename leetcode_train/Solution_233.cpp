//Given an integer n, count the total number of digit 1 appearing in all non - negative integers less than or equal to n.
//
//Example:
//
//Input: 13
//	Output : 6
//	Explanation : Digit 1 occurred in the following numbers : 1, 10, 11, 12, 13.

//if n = xyzdabc
//
//(1) xyz * 1000                     if d == 0
//(2) xyz * 1000 + abc + 1           if d == 1
//(3) xyz * 1000 + 1000              if d > 1

//d==0的情况
//如果n = 4560234
//让我们统计一下千位有多少个 1
//xyz 可以取 0 到 455, abc 可以取 0 到 999
//4551000 to 4551999 (1000)
//4541000 to 4541999 (1000)
//4531000 to 4531999 (1000)
//...
//  21000 to   21999 (1000)
//  11000 to   11999 (1000)
//   1000 to    1999 (1000)
//总共就是 456 * 1000


//如果 n = 4561234
//xyz 可以取 0 到 455, abc 可以取 0 到 999
//4551000 to 4551999 (1000)
//4541000 to 4541999 (1000)
//4531000 to 4531999 (1000)
//...
//   1000 to 1999 (1000)
//xyz 还可以取 456, abc 可以取 0 到 234
//4561000 to 4561234 (234 + 1)
//总共就是 456 * 1000 + 234 + 1
//
//如果 n = 4563234
//xyz 可以取 0 到 455, abc 可以取 0 到 999
//4551000 to 4551999 (1000)
//4541000 to 4541999 (1000)
//4531000 to 4531999 (1000)
//...
//   1000 to 1999 (1000)
//xyz 还可以取 456, abc 可以取 0 到 999，4561000 to 4561999 (1000)

//总共就是 456 * 1000 + 1000


class Solution_233 {
public:
	int countDigitOne(int n) {
		int count = 0;
		for (long k = 1; k <= n; k = k * 10) {
			// xyzdabc
			int abc = n % k;
			int xyzd = n / k;
			int d = xyzd % 10;
			int xyz = xyzd / 10;
			if (d == 0)
				count += xyz*k;
			else if (d == 1)
				count += xyz*k + abc + 1;
			else
				count += xyz*k + k;
		}
		return count;
	}

};