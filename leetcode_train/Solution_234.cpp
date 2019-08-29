#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include"ListNode.h"

using namespace std;

//Description
//Given a singly linked list, determine if it is a palindrome.
//
//Example 1:
//
//Input: 1->2
//	Output : false
//	Example 2 :
//
//	Input : 1->2->2->1
//	Output : true
//	Follow up :
//	   Could you do it in O(n) time and O(1) space ?



//���ȼ�������ĳ���
//������ĺ�벿������
//���Ԫ�ؽ��бȽ�

//�����ÿ���ָ�룬ʹָ��ָ���м��λ��
//Ȼ�����򣬲���Ҫ��������ĳ���

class Solution_234 {
	int compute_length(ListNode *head) {
		int length = 0;
		while (head) {
			length++;
			head = head->next;
		}
		return length;
	}
	ListNode *reverse_link(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *p1 = head;
		ListNode *p2 = p1->next;
		p1->next = NULL;
		while (p2) {
			ListNode *p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
		}
		return p1;
	}
public:
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return true;
		int length = compute_length(head);
		ListNode *pre_new_head = NULL;
		ListNode *new_head = head;
		for (int i = 0; i<length / 2; i++) {
			pre_new_head = new_head;
			new_head = new_head->next;
		}
		pre_new_head->next = NULL;
		new_head = reverse_link(new_head);
		while (new_head&&head) {
			if (new_head->val != head->val)
				return false;
			else
			{
				new_head = head->next;
				head = head->next;
			}
		}
		return true;
	}
};

//int main() {
//	ListNode *n1 = new ListNode(1);
//	ListNode *n2 = new ListNode(1);
//	ListNode *n3 = new ListNode(2);
//	ListNode *n4 = new ListNode(1);
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	Solution_234 s;
//	s.isPalindrome(n1);
//
//}