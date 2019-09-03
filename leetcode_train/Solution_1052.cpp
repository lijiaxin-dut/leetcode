#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//On some minutes, the bookstore owner is grumpy.  If the bookstore owner is grumpy on the i-th minute, 
//grumpy[i] = 1,otherwise grumpy[i] = 0.  When the bookstore owner is grumpy, the customers of that 
//minute are not satisfied, otherwise they are satisfied.

//The bookstore owner knows a secret technique to keep themselves not grumpy for X minutes straight, 
//but can only use it once.

//X分钟必须时连续的，在宽度为X的窗口中找到可以活跃最多的顾客的窗口
//单独考虑开始就可以服务的顾客数目
//然后初始化一个长度为X的窗口
//不断将窗口后移

class Solution_1052 {
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
		int rs = 0;
		//考虑所有不是grumpy的分钟
		for (int i = 0; i < grumpy.size(); i++) {
			if (grumpy[i] == 0)
				rs += customers[i];
		}
		int g_size = 0;
		int g_customer_number = 0;
		for (int i = 0; i < X; i++) {
			if (grumpy[i] == 1) {
				g_customer_number += customers[i];
			}
		}
		int left = 0;
		int right = left + X;
		int best_rs = rs + g_customer_number;
		while (right < grumpy.size()) {
			if (grumpy[right] == 1)
				g_customer_number += customers[right];
			if (grumpy[left] == 1)
				g_customer_number -= customers[left];
			best_rs = max(best_rs, rs + g_customer_number);
			left++;
			right++;
		}
		return best_rs;
	}
};

//int main() {
//	Solution_1052 s;
//	vector<int> customers{4,10,10 };
//	vector<int> grumpy{ 1,1,0 };
//	s.maxSatisfied(customers, grumpy, 2);
//
//}