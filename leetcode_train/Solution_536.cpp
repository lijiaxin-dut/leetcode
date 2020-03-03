#include<vector>
#include"TreeNode.h"
#include<string>
using namespace std;


//You need to construct a binary tree from a string consisting of parenthesis and integers.
//
//The whole input represents a binary tree.It contains an integer followed by zero, one or two pairs of parenthesis.The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.
//
//You always start to construct the left child node of the parent first if it exists.
//
//Example:
//
//Input: "4(2(3)(1))(6(5))"
//	Output : return the tree root node representing the following tree :
//
//	   4
//		   / \
//		   2     6
//		   / \ /
//		   3   1 5
//
//
//		   Note:
//
//	   There will only be '(', ')', '-' and '0' ~'9' in the input string.
//		   An empty tree is represented by "" instead of "()".


class Solution {
public:
	TreeNode* str2tree(string s) {
		if (s.empty()) 
			return NULL;
		auto found = s.find('(');
		int val = (found == string::npos) ? stoi(s) : stoi(s.substr(0, found));
		TreeNode *cur = new TreeNode(val);
		if (found == string::npos) 
			return cur;
		int start = found, cnt = 0;
		for (int i = start; i < s.size(); ++i) {
			if (s[i] == '(') 
				++cnt;
			else if (s[i] == ')')
				--cnt;
			if (cnt == 0 && start == found) {
				//需要去除掉左右两边的括号
				cur->left = str2tree(s.substr(start + 1, i - start - 1));
				start = i + 1;
				//i+1为下一个左括号的位置，即右子树，如果不存在右子树，循环就结束
			}
			else if (cnt == 0) {
				cur->right = str2tree(s.substr(start + 1, i - start - 1));
			}
		}
		return cur;
	}
};