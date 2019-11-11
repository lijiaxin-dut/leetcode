#include"TreeNode.h"
#include<algorithm>
#include<unordered_map>

using namespace std;

//�Ե����ϵݹ飬��sum���С��0ʱ������0


//����Ϊ�������
//�������ڵ�
//���������ڵ�
//ʹ��map�����Ѿ��ҵ����Ľ��

class Solution_124 {
	unordered_map<TreeNode *, int>hash_map;
public:
	int maxPathSum(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int rs = root->val + dfs(root->left) + dfs(root->right);
		int left = root->left == nullptr ? INT_MIN : maxPathSum(root->left);
		int right = root->right == nullptr ? INT_MIN : maxPathSum(root->right);
		return max(rs, max(left, right));
	}
	//��nodeΪ·���˵��path������
	int dfs(TreeNode* node) {
		if (hash_map.count(node) != 0)
			return hash_map[node];
		if (node == nullptr)
			return 0;
		int sum = node->val + max(dfs(node->left), dfs(node->right));
		if (sum<0) {
			hash_map[node] = 0;
			return 0;
		}
		else {
			hash_map[node] = sum;
			return sum;
		}
	}
};