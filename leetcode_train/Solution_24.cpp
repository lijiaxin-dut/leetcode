#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include"ListNode.h"

using namespace std;

//Given a linked list, swap every two adjacent nodes and return its head.
//
//You may not modify the values in the list's nodes, only nodes itself may be changed.
//
//
//
//Example:
//
//Given 1->2->3->4, you should return the list as 2->1->4->3.


//ʹ������ָ�룬����ָ���ָ�򼴿�
//��ͼ�������
//���������ڵ�

//���û�ͼ�������ָ���ָ��

class Solution_24 {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *dumy = new ListNode(0);
		dumy->next = head;
		ListNode *cur = dumy;
		while (cur->next&&cur->next->next) {
			auto next_pair = cur->next->next->next;
			auto cur_next = cur->next;
			cur->next = cur->next->next;
			cur->next->next = cur_next;
			cur_next->next = next_pair;
			cur = cur_next;
		}
		return dumy->next;

	}
};