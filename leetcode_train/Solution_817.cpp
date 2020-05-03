#include"ListNode.h"
#include<vector>
#include<unordered_set>

using namespace std;

//��G�ŵ������У��������
//�������������ǰ�����set�У��ͼ�����������ֱ������set��
//ʹ�ñ��λ��¼��ǰ�ִ��Ƿ�����set�еĽڵ�




class Solution_817 {
public:
	int numComponents(ListNode* head, vector<int>& G) {
		unordered_set<int>s(G.begin(), G.end());
		int rs = 0;
		while (head) {
			bool find = false;
			while (head&&s.count(head->val)) {
				head = head->next;
				find = true;
			}
			if (find)
				rs++;
			else
				head = head->next;
		}
		return rs;
	}
};