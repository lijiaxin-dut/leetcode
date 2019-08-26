#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include"ListNode.h"

using namespace std;

//Description
//Given a linked list, return the node where the cycle begins.If there is no cycle, return null.
//To represent a cycle in the given linked list, we use an integer pos which represents the 
//position(0 - indexed) in the linked list where 
//tail connects to.If pos is - 1, then there is no cycle in the linked list.

//p-> 2 steps
//q-> 1 step
//p==q , find cycle ,break;
//p= head
//p->1 step
//q->1 step 
//p��q���ʱ�����ǻ������

//���軷�ĳ���ΪL,��㵽������ľ���Ϊk,ͷ��������������Ϊm
//dist_p=m+P*L+k,PΪתȦ�Ĵ���
//dist_q=m+Q*L+k,QΪתȦ�Ĵ���
//dist_p=2*dist_q
//m+P*L+k=2*m+2*Q*L+2*k
//0=m+k+2QL-PL=m+k+L(2Q-P)
//m+k=L(P-2Q)
//m+k=int*L

//p�ߵĳ���һ����m�������͵��˻������

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return NULL;
		ListNode *fast = head;
		ListNode *slow = head;
		bool has_cycle = false;
		while (fast->next&&fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (slow == fast) {
				has_cycle = true;
				break;
			}
		}
		if (has_cycle == false)
			return NULL;
		fast = head;
		while (fast != slow) {
			fast = fast->next;
			slow = slow->next;
		}
		return fast;

	}
};