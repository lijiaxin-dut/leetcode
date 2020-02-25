#include<list>
using namespace std;


//0, 1, , n - 1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。
//
//例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
//
//
//
//示例 1：
//
//输入 : n = 5, m = 3
//	输出 : 3
//	示例 2：
//
//	输入 : n = 10, m = 17
//	输出 : 2
//


//1.使用连表模拟环

class Solution {
public:
	int lastRemaining(int n, int m) {
		list<int>l;
		for (int i = 0; i<n; i++)
			l.push_back(i);
		auto it = l.begin();
		int cur_index = 1;
		while (l.size()>1) {
			if (it == l.end())
				it = l.begin();
			if (cur_index == m) {
				it = l.erase(it);
				cur_index = 1;
			}
			else {
				cur_index++;
				it++;
			}
		}
		return l.front();

	}
};
