#include"ListNode.h"
#include<vector>
#include<unordered_set>

using namespace std;

//��G�ŵ������У��������
//�������������ǰ�ڵ���G�в�����һ���ڵ�Ҳ��G�У��ͼ�������
//����rs++



class Solution_817 {
public:
	int numComponents(ListNode* head, vector<int>& G) {
		unordered_set<int>hash_set(G.begin(), G.end());
		int rs = 0;
		while (head != nullptr) {
			if (hash_set.count(head->val) != 0) {
				if (head->next != nullptr&&hash_set.count(head->next->val) != 0) {
					head = head->next;
				}
				else {
					rs++;
					head = head->next;
				}
			}
			else
				head = head->next;
		}
		return rs;
	}
};