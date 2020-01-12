#include"ListNode.h"


//
//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//k is a positive integer and is less than or equal to the length of the linked list.If the number of nodes is not a multiple of k then left - out nodes in the end should remain as it is.
//
//Example:
//
//Given this linked list : 1->2->3->4->5
//
//For k = 2, you should return : 2->1->4->3->5
//
//For k = 3, you should return : 3->2->1->4->5



//一边遍历一遍将链表进行反转
//注意链表不要断开

//


class Solution_25 {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k == 1 || head == nullptr)
			return head;
		ListNode *cur_head = head;
		ListNode *cur_next_head = head;
		ListNode *dumy = new ListNode(0);
		ListNode *pre_tail = dumy;
		dumy->next = head;
		while (cur_head != nullptr) {
			int n = k;
			while (n>1 && cur_next_head != nullptr) {
				cur_next_head = cur_next_head->next;
				n--;
			}
			if (n == 1 && cur_next_head != nullptr) {
				auto back_next = cur_next_head->next;
				cur_next_head->next = nullptr;
				//下一个区间的头部
				cur_next_head = back_next;
				cur_head = reverseLinkList(cur_head);
				//上一个区间的尾部
				pre_tail->next = cur_head;
				while (cur_head->next != nullptr)
					cur_head = cur_head->next;
				//当前区间的尾部
				cur_head->next = cur_next_head;
				//更新下一次迭代的值
				pre_tail = cur_head;
				cur_head = cur_next_head;
			}
			else
				break;
		}
		return dumy->next;

	}
	//链表倒置
	ListNode *reverseLinkList(ListNode *cur_head) {
		if (cur_head == nullptr || cur_head->next == nullptr)
			return nullptr;
		ListNode *p1 = cur_head;
		ListNode *p2 = cur_head->next;
		cur_head->next = nullptr;
		while (p2) {
			ListNode*p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
		}
		return p1;
	}
};

