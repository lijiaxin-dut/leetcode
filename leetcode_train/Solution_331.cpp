#include<string>
#include<sstream>
#include<vector>

using namespace std;



//One way to serialize a binary tree is to use pre - order traversal.When we encounter a non - null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
//
//_9_
/// \
//3     2
/// \ / \
//4   1  #  6
/// \ / \ / \
//# # # #   # #
//For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

//判断一个序列化的二叉树是不是合法的
//二叉树的 空指针数目==节点数目+1

//如果 空指针数目>节点数+1  不合法
//     空指针数<节点数+1    不完整的二叉树
//     空指针数==节点数+1   不允许有后续节点







class Solution_331 {
public:
	//使用栈，不断消去叶子节点，当出现 value,#,# 时，就替换为#
	//最后应该只有一个#
	bool isValidSerialization_stack(string preorder) {
		if (preorder == "#")
			return true;
		stringstream ss(preorder);
		vector<string>s;
		while (getline(ss, preorder, ',')) {
			s.push_back(preorder);
			while (s.size() >= 3) {
				int s_size = s.size();
				if (s[s_size - 1] == "#"&&s[s_size - 2] == "#"&&s[s_size - 3] != "#") {
					s.pop_back();
					s.pop_back();
					s.pop_back();
					s.push_back("#");
				}
				else
					break;
			}
		}
		return s.size() == 1 && s[0] == "#";
	}
	bool isValidSerialization(string preorder) {
		if (preorder == "#")
			return true;
		stringstream ss(preorder);
		vector<string>split_preorder;
		string temp;
		while (getline(ss, temp, ',')) {
			split_preorder.push_back(temp);
		}
		int node_cnt = 0;
		int null_cnt = 0;
		//除了末尾，是否有连续的三个＃      
		for (int i = 0; i<split_preorder.size(); i++) {
			if (split_preorder[i] == "#")
				null_cnt++;
			else
				node_cnt++;
			if (null_cnt >= node_cnt + 1 && i != split_preorder.size() - 1)
				return false;
		}
		return null_cnt == node_cnt + 1;
	}
};