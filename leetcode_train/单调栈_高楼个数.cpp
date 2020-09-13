#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


//链接：https://www.nowcoder.com/questionTerminal/35fac8d69f314e958a150c141894ef6a
//
//小Q在周末的时候和他的小伙伴来到大城市逛街，一条步行街上有很多高楼，共有n座高楼排成一行。
//小Q从第一栋一直走到了最后一栋，小Q从来都没有见到这么多的楼，所以他想知道他在每栋楼的位置处能看到多少栋楼呢？（当前面的楼的高度大于等于后面的楼时，后面的楼将被挡住）
//
//输入描述 :
//输入第一行将包含一个数字n，代表楼的栋数，接下来的一行将包含n个数字wi(1 <= i <= n)，代表每一栋楼的高度。
//1 <= n <= 100000;
//1 <= wi <= 100000;
//
//
//输出描述:
//输出一行，包含空格分割的n个数字vi，分别代表小Q在第i栋楼时能看到的楼的数量。
//示例1
//输入
//6
//5 3 8 3 2 5
//输出
//3 3 5 4 4 4


class Solution {
public:
	void calculate() {
		int n, x[100001];
		cin >> n;
		int ans = 0;
		vector<int> a, b;
		stack<int> st1, st2;
		for (int i = 0; i < n; i++) cin >> x[i];

		for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
			a.push_back(st1.size());
			b.push_back(st2.size());

			while (!st1.empty() && st1.top() <= x[i]) st1.pop();
			while (!st2.empty() && st2.top() <= x[j]) st2.pop();
			st1.push(x[i]);
			st2.push(x[j]);
		}
		reverse(b.begin(), b.end());
		for (int i = 0; i < n; i++) cout << b[i] + a[i] + 1 << " ";
		return ;
	}

};
