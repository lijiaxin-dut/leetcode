#include<vector>
#include"TreeNode.h"

using namespace std;

//����һ�Ŷ������Ͷ�������ǰ�����
//�ж��ܷ񽻻������������ҽڵ㣬ʹ��ǰ������Ľ������ȷ��

//ʼ���жϵ�ǰ�ڵ��Ƿ��������еĽڵ����
//Ȼ���ж��������Ƿ�����һ�������е��������

//������ȣ����ȱ����������������������
//



class Solution_971 {
public:
	vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
		int index = 0;
		vector<int>rs;
		dfs(rs, root, index, voyage);
		if (!rs.empty() && rs[0] == -1)
		{
			rs.clear();
			rs.push_back(-1);
		}
		return rs;
	}
	void dfs(vector<int>&rs, TreeNode*x, int &index, vector<int>& voyage) {
		if (x == NULL)
			return;
		if (x->val != voyage[index]) {
			rs.clear();
			rs.push_back(-1);
			return;
		}
		index++;
		if (x->left != NULL&&x->left->val != voyage[index]) {
			rs.push_back(x->val);
			dfs(rs, x->right, index, voyage);
			dfs(rs, x->left, index, voyage);
		}
		else {
			dfs(rs, x->left, index, voyage);
			dfs(rs, x->right, index, voyage);
		}

	}
};