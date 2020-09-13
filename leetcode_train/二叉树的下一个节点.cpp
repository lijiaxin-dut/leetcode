
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {

	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{

		if (pNode == nullptr) {
			return pNode;
		}

		if (pNode->right) {

			pNode = pNode->right;
			while (pNode&&pNode->left) {
				pNode = pNode->left;
			}
			return pNode;
		}
		while (pNode->next) {
			if (pNode->next->left == pNode) {
				return pNode->next;
			}
			pNode = pNode->next;
		}
		return nullptr;


	}


};