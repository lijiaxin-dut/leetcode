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

//�ж�һ�����л��Ķ������ǲ��ǺϷ���
//�������� ��ָ����Ŀ==�ڵ���Ŀ+1

//��� ��ָ����Ŀ>�ڵ���+1  ���Ϸ�
//     ��ָ����<�ڵ���+1    �������Ķ�����
//     ��ָ����==�ڵ���+1   �������к����ڵ�







class Solution_331 {
public:
	//ʹ��ջ��������ȥҶ�ӽڵ㣬������ value,#,# ʱ�����滻Ϊ#
	//���Ӧ��ֻ��һ��#
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
		//����ĩβ���Ƿ���������������      
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