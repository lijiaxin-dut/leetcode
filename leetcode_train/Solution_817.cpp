#include"ListNode.h"
#include<vector>
#include<unordered_set>

using namespace std;

//��G�ŵ������У��������
//�������������ǰ�����set�У��ͼ�����������ֱ������set��
//ʹ�ñ��λ��¼��ǰ�ִ��Ƿ�����set�еĽڵ�




class Solution {
public:
	int numComponents(ListNode* head, vector<int>& G) {
		unordered_set<int>nums(G.begin(), G.end());
		int rs = 0;
		while (head) {
			if (nums.find(head->val) != nums.end()) {
				while (head&&nums.find(head->val) != nums.end()) {
					nums.erase(head->val);
					head = head->next;
				}
				rs++;
			}
			else {
				head = head->next;
			}
		}
		return rs;
	}
};