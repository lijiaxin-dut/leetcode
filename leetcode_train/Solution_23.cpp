#include"ListNode.h"
#include<vector>

using namespace std;

//Merge k sorted linked lists and return it as one sorted list.Analyze and describe its complexity.
//
//Example:
//
//Input:
//[
//	1->4->5,
//	1->3->4,
//	2->6
//]
//Output : 1->1->2->3->4->4->5->6



//1.不断的将链表合并到第一个链表上即可，调用合并两个链表的函数
//2.分治的思想，合并的过程中，尽可能保持每个了链表的长度相等，尽可能两两合并
//0 1 2 3 4 
//0 3   1 4
//每次将链表的个数缩小一半
//注意奇数跟偶数


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution_23 {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
			return NULL;
		int n = lists.size();
		while (n > 1) {
			int k = (n + 1) / 2;
			for (int i = 0; i<n / 2; i++)
				lists[i] = mergeTwoLists(lists[i], lists[i + k]);
			n = k;

		}
		return lists[0];
	}
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