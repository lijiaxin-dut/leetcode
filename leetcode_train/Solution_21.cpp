#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include"ListNode.h"

using namespace std;



//Merge two sorted linked lists and return it as a new list.The new list should be 
//made by splicing together the nodes of the first two lists.
//
//Example:
//
//Input: 1->2->4, 1->3->4
//	Output : 1->1->2->3->4->4





/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/


class Solution_21 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode *current_node = new ListNode(-1);
		ListNode *head = current_node;
		while (l1 != NULL&&l2 != NULL) {
			if (l1->val >= l2->val) {
				current_node->next = l2;
				current_node = current_node->next;
				l2 = l2->next;
			}
			else
			{
				current_node->next = l1;
				current_node = current_node->next;
				l1 = l1->next;
			}
		}
		if (l1 != NULL)
			current_node->next = l1;
		if (l2 != NULL)
			current_node->next = l2;
		return head->next;


	}
};