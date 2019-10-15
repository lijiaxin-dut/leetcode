#include"ListNode.h"
#include<iostream>

using namespace std;

//�������ڵ��ʾ��С��ֵ

//����ǰ�ڵ���ͷ���ڵ����ο�ʼ�Ƚ�
//�ҵ���һ�����ڵĽڵ�
//���뵽�ýڵ�ĺ���

//��������λ�ò�������

class Solution_147 {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *dumy = new ListNode(INT_MIN);
		dumy->next = head;
		ListNode*pre = head;
		head = head->next;
		while (head != NULL) {
			pre->next = head->next;
			//���뵽h1�����λ�ã���Ҫ��¼h1��pre�ڵ�
			for (ListNode *h1 = dumy, *inside_pre = dumy; h1 != pre->next; inside_pre = h1, h1 = h1->next) {
				if (head->val < h1->val) {
					inside_pre->next = head;
					head->next = h1;
					break;
				}
			}
			//���������λ�ò������仯
			if (head->next == pre->next) {
				pre->next = head;
				pre = head;
				head = head->next;
			}
			else
				head = pre->next;
		}
		return dumy->next;

	}
};

//int main() {
//	Solution_147 s;
//	ListNode *n1 = new ListNode(-1);
//	ListNode *n2 = new ListNode(5);
//	n1->next = n2;
//	ListNode *n3 = new ListNode(3);
//	n2->next = n3;
//	ListNode *n4 = new ListNode(4);
//	n3->next = n4;
//	s.insertionSortList(n1);
//}