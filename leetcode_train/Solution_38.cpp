#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>


using namespace std;

//The count - and-say sequence is the sequence of integers with the first five terms as following :
//
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.

//下一个的输出依赖于上一个结果
//111221 有三个1两个2一个1构成
//312211

class Solution_38 {
public:
	string countAndSay(int n) {
		string last = to_string(1);
		while (n >= 2)
		{
			n--;
			int count = 1;
			string new_s = "";
			for (int i = 0; i<last.size() - 1; i++) {
				if (last[i] == last[i + 1])
					count++;
				else {
					new_s += to_string(count) + last[i];
					count = 1;
				}
			}
			new_s += to_string(count) + last.back();
			last = new_s;

		}
		return last;
	}
};
