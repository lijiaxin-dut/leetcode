#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<stack>
#include<sstream>
#include"ListNode.h"

using namespace std;
//
//Reverse a linked list from position m to n.Do it in one - pass.
//
//Note: 1 ≤ m ≤ n ≤ length of list.
//
//	Example :
//
//	Input : 1->2->3->4->5->NULL, m = 2, n = 4
//	Output : 1->4->3->2->5->NULL
//

//定位到m\n所在的位置
//将中间的区间逆序
//后拼接为一个完整的链表

class Solution_92 {
	ListNode *reverse(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *p1 = head;
		ListNode*p2 = p1->next;
		ListNode *p3 = NULL;
		p1->next = NULL;
		while (p2) {
			p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
		}
		return p1;
	}
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL || head->next == NULL || m == n)
			return head;
		ListNode *dumy = new ListNode(-1);
		dumy->next = head;
		int i = 0;
		ListNode *m_node = dumy;
		ListNode *pre_m_node = dumy;
		while (i<m) {
			pre_m_node = m_node;
			m_node = m_node->next;
			i++;
		}
		i = 0;
		ListNode *n_node = dumy;
		while (i<n) {
			n_node = n_node->next;
			i++;
		}
		ListNode*after_n_node = n_node->next;
		n_node->next = NULL;
		pre_m_node->next = NULL;
		//reverse中间的链表
		ListNode *interval_head = reverse(m_node);
		pre_m_node->next = interval_head;
		while (interval_head->next != NULL)
			interval_head = interval_head->next;
		interval_head->next = after_n_node;
		return dumy->next;
	}
};