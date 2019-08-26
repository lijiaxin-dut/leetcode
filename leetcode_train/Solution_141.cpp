#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include"ListNode.h"

using namespace std;

//Description
//Given a linked list, determine if it has a cycle in it.
//To represent a cycle in the given linked list, we use an integer pos which represents 
//the position(0 - indexed) in the linked list where tail connects to.If pos is - 1, then 
//there is no cycle in the linked list.

//ʹ�ÿ�������ָ�룬���ѭ���Ĺ���������ָ����ȣ���˵���л�

class Solution_141 {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return false;
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast->next&&fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
				return true;
		}
		return false;
	}
};
