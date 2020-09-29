#include<string>
#include<vector>
using namespace std;





// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
   public:
    // Constructor initializes an empty nested list.
     NestedInteger();

     // Constructor initializes a single integer.
     NestedInteger(int value);

     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Set this NestedInteger to hold a single integer.
     void setInteger(int value);

     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
     void add(const NestedInteger &ni);

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
 };

//s不为空的话看首字符是否为’[’，不是的话说明s为一个整数，我们直接返回结果。

//如果s中首字符是’[’，且s长度小于等于2，说明没有内容，直接返回结果。（’[‘或’[]’）

//如果s长度大于2，我们从i = 1开始遍历，我们需要一个变量start来记录某一层的真实位置，
//用cnt来记录跟真实位置是否为同一深度，cnt = 0表示同一深度，
//由于中间每段都是由逗号隔开，所以当我们判断当cnt为0，且当前字符是逗号或者已经到字符串末尾了，
//我们把start到当前位置之间的字符串取出来递归调用函数，
//把返回结果加入res中，然后start更新为i + 1。如果遇到’[’，计数器cnt自增1，若遇到’]’，计数器cnt自减1。

class Solution {
public:
	NestedInteger deserialize(string s) {

		if (s.empty()) {
			return NestedInteger();
		}
		if (s[0] != '[') {
			return NestedInteger(stoi(s));
		}
		if (s.size() <= 2) {
			return NestedInteger();
		}
		NestedInteger res;
		int start = 1, cnt = 0;
		for (int i = 1; i<s.size(); i++) {
			if (cnt == 0 && (s[i] == ',') || i == s.size() - 1) {
				string sub = s.substr(start, i - start);
				res.add(deserialize(sub));
				start = i + 1;
			}
			else if (s[i] == '[') {
				cnt++;
			}
			else if (s[i] == ']') {
				cnt--;
			}
		}
		return res;
	}
};