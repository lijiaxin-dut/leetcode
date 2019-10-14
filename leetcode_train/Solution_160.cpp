#include"ListNode.h"
#include<iostream>

//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//For example, the following two linked lists :


//���̳�����ĳ���
//���α�������
//�ҵ���ͬ�ĵ㼴��


//������������ƶ�
//��p1Ϊ��ʱ��ָ��headB
//��p2Ϊ��ʱ��ָ��headA
//�൱�ڰ���������

class Solution_160 {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *p1 = headA;
		ListNode *p2 = headB;

		int diff_length = 0;
		while (p1 != NULL&&p2 != NULL) {
			if (p1 == p2)
				return p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		while (p1 != NULL) {
			p1 = p1->next;
			headA = headA->next;
			diff_length++;
		}
		while (p2 != NULL) {
			p2 = p2->next;
			headB = headB->next;
			diff_length++;
		}
		while (headA != headB)
		{
			headA = headA->next;
			headB = headB->next;
		}
		return headA;
	}
	ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB) {
		ListNode *p1 = headA;
		ListNode *p2 = headB;
		while (p1 != p2) {
			if (p1 == NULL)
				p1 = headB;
			else
				p1 = p1->next;
			if (p2 == NULL)
				p2 = headA;
			else
				p2 = p2->next;
		}
		return p1;

	}
};