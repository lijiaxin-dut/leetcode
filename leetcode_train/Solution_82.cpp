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


//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
//Example 1:
//
//Input: 1->2->3->3->4->4->5
//	Output : 1->2->5
//	Example 2 :
//
//	Input : 1->1->1->2->3
//	Output : 2->3


//增加一个虚拟头节点，用于删除开始就重复的节点[1,1,1,1,1,2]
//保存三个指针
//pre表示上一个不重复的节点
//cur表示当前判断的节点
//next表示cur的后一个节点

//单独考虑一个节点或者空链表

class Solution_82 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *dumy = new ListNode(-1);
		dumy->next = head;
		ListNode *pre = dumy;
		ListNode *curr = dumy->next;
		ListNode *next = curr->next;
		while (curr != NULL&&curr->next != NULL) {
			if (curr->val == next->val) {
				while (next != NULL&&curr->val == next->val)
					next = next->next;
				//找到了不相等的下一个节点
				//[1,2,3,3,3,4,4,5,5,6]
				//找到了4
				pre->next = next;
				curr = next;
				if (next != NULL)
					next = next->next;
			}
			else {
				pre = curr;
				curr = curr->next;
				next = next->next;
			}
		}
		return dumy->next;
	}
};