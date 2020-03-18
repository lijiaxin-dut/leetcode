#include<string>
#include<algorithm>
using namespace std;

//Given a non - negative integer, you could swap two digits at most once to get the maximum valued number.Return the maximum valued number you could get.
//
//Example 1:
//Input: 2736
//	Output : 7236
//	Explanation : Swap the number 2 and the number 7.


//找到第一个存在右侧最大值的位置，交换这两个位置

class Solution {

public:
	int maximumSwap(int num) {
		string s_num = to_string(num);
		int n = s_num.size();
		int right_max_val = -1;
		int right_max_index = 0;//从右向左，当前最大值
		int left_index = -1;
		int right_index = -1;
		for (int i = n - 1; i >= 0; i--) {
			if (s_num[i]>right_max_val) {
				right_max_val = s_num[i];
				right_max_index = i;
				continue;
			}
			if (s_num[i]<right_max_val) {
				left_index = i;
				right_index = right_max_index;
			}
		}
		if (left_index == -1)
			return num;
		swap(s_num[left_index], s_num[right_index]);
		return stoi(s_num);

	}
};