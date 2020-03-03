#include"ListNode.h"
#include<stack>

using namespace std;
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

//You are given two non - empty linked lists representing two non - negative integers.The most significant digit comes first and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Follow up :
//What if you cannot modify the input lists ? In other words, reversing the lists is not allowed.


//1.将输入链表倒序，然后求和，再将结果倒序

//2.链表的数据存入栈中，每次生成新的节点放在头部

class Solution {
public:
	ListNode* addTwoNumbers_no_reverse(ListNode* l1, ListNode* l2) {
		stack<int>s1;
		stack<int>s2;
		while (l1) {
			s1.push(l1->val);
			l1 = l1->next;
		}
		while (l2) {
			s2.push(l2->val);
			l2 = l2->next;
		}
		ListNode *cur = new ListNode(0);
		while (!s2.empty() || !s1.empty()) {
			int sum = 0;
			if (!s1.empty()) {
				sum += s1.top();
				s1.pop();
			}
			if (!s2.empty()) {
				sum += s2.top();
				s2.pop();
			}
			sum += cur->val;
			cur->val = sum % 10;
			ListNode*new_node = new ListNode(sum / 10);
			new_node->next = cur;
			cur = new_node;
		}
		return cur->val == 0 ? cur->next : cur;
	}
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr&&l2 == nullptr)
			return nullptr;
		else if (l1 == nullptr)
			return l2;
		else if (l2 == nullptr)
			return l1;
		l1 = reverseList(l1);
		l2 = reverseList(l2);
		int carry = 0;
		ListNode *dumy = new ListNode(-1);
		ListNode *cur = dumy;

		while (l1 || l2 || carry) {
			int val1 = l1 != nullptr ? l1->val : 0;
			int val2 = l2 != nullptr ? l2->val : 0;
			int val = val1 + val2 + carry;
			carry = val / 10;
			ListNode*new_node = new ListNode(val % 10);
			cur->next = new_node;
			cur = cur->next;
			l1 = l1 != nullptr ? l1->next : nullptr;
			l2 = l2 != nullptr ? l2->next : nullptr;

		}
		ListNode*new_head = dumy->next;
		dumy->next = nullptr;
		return reverseList(new_head);
	}
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr)
			return nullptr;
		ListNode *p1 = head;
		ListNode *p2 = head->next;
		ListNode *p3;
		while (p2) {
			p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
		}
		head->next = nullptr;
		return p1;
	}
};