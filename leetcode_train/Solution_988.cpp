#include<vector>
#include<string>
#include"TreeNode.h"

using namespace std;


//Given the root of a binary tree, each node has a value from 0 to 25 representing the letters 'a' to 'z': a value of 0 represents 'a', a value of 1 represents 'b', and so on.
//
//Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.
//
//(As a reminder, any shorter prefix of a string is lexicographically smaller : for example, "ab" is lexicographically smaller than "aba".A leaf of a node is a node that has no children.)
//

//dfs

class Solution_988 {
	vector<char>m{ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
public:
	string smallestFromLeaf(TreeNode* root) {
		string rs;
		string partial_rs;
		dfs(root, rs, partial_rs);
		return rs;
	}
	void dfs(TreeNode*x, string &rs, string &current_str) {
		if (x == NULL)
			return;
		current_str.push_back(m[x->val]);
		if (x->left == NULL&&x->right == NULL) {
			reverse(current_str.begin(), current_str.end());
			//cout<<current_str<<endl;
			if (current_str<rs || rs.empty())
				rs = current_str;
			reverse(current_str.begin(), current_str.end());
			current_str.pop_back();
			return;
		}
		if (x->left)
			dfs(x->left, rs, current_str);
		if (x->right)
			dfs(x->right, rs, current_str);
		current_str.pop_back();
	}
};