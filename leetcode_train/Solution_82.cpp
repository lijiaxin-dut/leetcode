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


//����һ������ͷ�ڵ㣬����ɾ����ʼ���ظ��Ľڵ�[1,1,1,1,1,2]
//��������ָ��
//pre��ʾ��һ�����ظ��Ľڵ�
//cur��ʾ��ǰ�жϵĽڵ�
//next��ʾcur�ĺ�һ���ڵ�

//��������һ���ڵ���߿�����

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
				//�ҵ��˲���ȵ���һ���ڵ�
				//[1,2,3,3,3,4,4,5,5,6]
				//�ҵ���4
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