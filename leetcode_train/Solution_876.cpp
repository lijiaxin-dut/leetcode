#include"ListNode.h"

//Given a non - empty, singly linked list with head node head, return a middle node of linked list.
//
//If there are two middle nodes, return the second middle node.


//¿ìÂýÖ¸Õë


class Solution_876 {
public:
	ListNode* middleNode(ListNode* head) {
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast&&fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;


	}
};