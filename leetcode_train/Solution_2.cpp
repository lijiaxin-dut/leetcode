#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include"ListNode.h"

using namespace std;
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

//You are given two non - empty linked lists representing two non - negative integers.
//The digits are stored in reverse order and each of their nodes contain a single digit.
//Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.


//ע�ⳤ�Ȳ���ȵĴ���
//ע�����һ����λ


class Solution_2 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode *head = l1;
		//��¼��һ��λ��
		ListNode *pre_l1 = l1;
		//��¼��һ��λ��
		ListNode *pre_l2 = l2;
		int carry = 0;
		while (l1 != NULL&&l2 != NULL) {
			l1->val += l2->val + carry;
			pre_l1 = l1;
			pre_l2 = l2;
			carry = l1->val / 10;
			l1->val %= 10;
			l1 = l1->next;
			l2 = l2->next;
		}
		//l2�Ƚϳ�
		if (l2 != NULL) {
			pre_l2->next = NULL;
			pre_l1->next = l2;
			l1 = pre_l1->next;
		}
		//�����λ
		while (l1 != NULL) {
			l1->val += carry;
			carry = l1->val / 10;
			l1->val %= 10;
			pre_l1 = l1;
			l1 = l1->next;
		}
		//������һλ
		if (carry != 0) {
			ListNode *last = new ListNode(1);
			pre_l1->next = last;
		}
		return head;
	}
};
