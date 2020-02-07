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
//tail��ʾ�����β���ڵ�
//cur��ʾ��ǰ�жϵĽڵ�
//pre��ʾcur֮ǰ�Ľڵ�

//��������һ���ڵ���߿�����
//�����β���ظ�����������curΪ��

class Solution_82 {
public:

	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode *dumy = new ListNode(-1);
		dumy->next = head;
		ListNode *cur = head->next;
		ListNode *pre = head;
		ListNode *tail = dumy;//��ǰ��β�ڵ�
		while (cur) {
			//����ȵ�ֵʱ��������ƶ�
			if (cur->val == pre->val) {
				pre = pre->next;
				cur = cur->next;
			}
			//��ֵ�����ʱ���ж�tail->next��pre�Ƿ���ȣ�
			//���ж�pre�Ƿ��ڴ���
			//��tail->next != pre ˵��pre���ڴ��У���tail->nextָ��cur
			else if (tail->next != pre&&cur->val != pre->val) {
				tail->next = cur;
				pre = cur;
				cur = cur->next;
			}
			//��tail->next == pre ˵��pre�ڴ��У�
			//��tail,pre,cur������������ָ��
			//��pre�������
			
			else if (tail->next == pre&&cur->val != pre->val) {
				tail = pre;
				pre = pre->next;
				cur = cur->next;
			}
		}
		//�ж�����Ƿ�����ظ��Ľڵ㣬��Ϊpreָ�����һ���ڵ㣬curΪ�գ�
		if (tail->next != pre)
			tail->next = nullptr;
		//ע�⽫����β���ÿ�
		return dumy->next;
	}
};