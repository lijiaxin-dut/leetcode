#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<memory>
#include<unordered_map>
#include<set>
#include<queue>
#include"ListNode.h"
#include<stack>

using namespace std;

//Given a singly linked list L : L0→L1→…→Ln - 1→Ln,
//reorder it to : L0→Ln→L1→Ln - 1→L2→Ln - 2→…
//
//You may not modify the values in the list's nodes, only nodes itself may be changed.
//
//Example 1 :
//
//	Given 1->2->3->4, reorder it to 1->4->2->3.
//	Example 2 :
//
//	Given 1->2->3->4->5, reorder it to 1->5->2->4->3.


//使用快慢两个指针，找到链表的终点
//将后半段链表放入栈中
//不断的插入到前半部分中



class Solution_143 {

public:
	void reorderList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return;
		ListNode*fast = head;
		ListNode*slow = head;
		while (fast->next&&fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		stack<ListNode*>nodes;
		ListNode*back_new_head = slow;
		slow = slow->next;
		back_new_head->next = NULL;
		while (slow) {
			nodes.push(slow);
			slow = slow->next;
		}

		while (!nodes.empty()) {
			auto current_node = nodes.top();
			nodes.pop();
			ListNode*next = head->next;
			head->next = current_node;
			current_node->next = next;
			head = next;
		}
	}
};


