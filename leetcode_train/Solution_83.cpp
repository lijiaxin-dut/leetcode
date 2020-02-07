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

//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//Example 1:
//
//Input: 1->1->2
//	Output : 1->2
//	Example 2 :
//
//	Input : 1->1->2->3->3
//	Output : 1->2->3

//给定一个curr指针，和指向下一个位置的指针
//找到与curr指针不相等的位置，更新next指针即可


class Solution_83 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode *cur = head->next;
		ListNode *pre = head;
		while (cur) {
			if (cur->val == pre->val) {
				cur = cur->next;
			}
			else {
				pre->next = cur;
				pre = pre->next;
				cur = cur->next;
			}
		}
		pre->next = nullptr;
		return head;
	}
};