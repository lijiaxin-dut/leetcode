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
	
	public:
		ListNode* insertionSortList(ListNode* head) {
			if (head == nullptr || head->next == nullptr)
				return head;
			ListNode*dumy = new ListNode(INT_MIN);
			dumy->next = head;
			ListNode*cur = head->next;
			ListNode*pre_cur = head;
			while (cur) {
				ListNode*inside_pre = dumy;
				ListNode*inside_head = head;
				ListNode*cur_next = cur->next;
				while (inside_head != cur) {
					if (cur->val <= inside_head->val) {
						inside_pre->next = cur;
						cur->next = inside_head;
						break;
					}
					inside_pre = inside_head;
					inside_head = inside_head->next;

				}
				//cur�Ѿ�����ȷ��λ����
				if (inside_head == cur) {
					pre_cur = cur;
					cur = cur->next;
				}
				//cur��λ�÷����ı�
				else {
					cur = cur_next;
					pre_cur->next = cur;
				}

			}
			return dumy->next;
		}

	
};

