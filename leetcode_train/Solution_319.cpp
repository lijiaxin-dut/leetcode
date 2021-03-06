#include<vector>

using namespace std;

//There are n bulbs that are initially off.You first turn on all the bulbs.
//Then, you turn off every second bulb.On the third round, 
//you toggle every third bulb(turning on if it's off or turning off if it's on).
//For the i - th round, you toggle every i bulb.For the n - th round, 
//you only toggle the last bulb.Find how many bulbs are on after n rounds.
//
//Example:
//
//Input: 3
//	Output : 1
//	Explanation :
//	At first, the three bulbs are[off, off, off].
//	After first round, the three bulbs are[on, on, on].
//	After second round, the three bulbs are[on, off, on].
//	After third round, the three bulbs are[on, off, off].
//
//	So you should return 1, because there is only one bulb is on.

//1.按照流程走循环即可
//2.找规律，最后亮的灯泡是完全平方数对应的索引
//对于第n个灯泡，只有当次数是n的因子的之后，才能改变灯泡的状态，即n能被当前次数整除，
//比如当n为36时，它的因数有(1,36), (2,18), (3,12), (4,9), (6,6), 
//可以看到前四个括号里成对出现的因数各不相同，
//括号中前面的数改变了灯泡状态，后面的数又变回去了，
//等于灯泡的状态没有发生变化，只有最后那个(6,6)，
//在次数6的时候改变了一次状态，没有对应其它的状态
//能将其变回去了，所以灯泡就一直是点亮状态的。
//所以所有平方数都有这么一个相等的因数对，即所有平方数的灯泡都将会是点亮的状态。



class Solution_319 {
public:
	int bulbSwitch_1(int n) {
		int rs = 0;
		for (int i = 1; i*i <= n; i++) {
			rs++;
		}
		return rs;
	}
	int bulbSwitch(int n) {
		vector<bool>mark(n + 1, false);
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j = j + i) {
				mark[i] = !mark[i];
			}
		}
		int rs = 0;
		for (int i = 1; i <= n; i++) {
			if (mark[i] == true)
				rs++;
		}
		return rs;

	}
};

//int main() {
//	Solution_319 s;
//	s.bulbSwitch(3);
//}