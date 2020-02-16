#include"ListNode.h"
#include<iostream>

using namespace std;

//添加虚拟节点表示最小的值

//将当前节点与头部节点依次开始比较
//找到第一个大于的节点
//插入到该节点的后面

//单独考虑位置不变的情况

class Solution_147 {
public:
	
	public:
		ListNode* insertionSortList(ListNode* head) {
			if (head == nullptr || head->next == nullptr)
				return head;
			ListNode*dumy = new ListNode(INT_MIN);
			dumy->next = head;
			ListNode*cur = head->next;
			ListNode*pre_cur = head;
			while (cur) {
				ListNode*inside_pre = dumy;
				ListNode*inside_head = head;
				ListNode*cur_next = cur->next;
				while (inside_head != cur) {
					if (cur->val <= inside_head->val) {
						inside_pre->next = cur;
						cur->next = inside_head;
						break;
					}
					inside_pre = inside_head;
					inside_head = inside_head->next;

				}
				//cur已经在正确的位置上
				if (inside_head == cur) {
					pre_cur = cur;
					cur = cur->next;
				}
				//cur的位置发生改边
				else {
					cur = cur_next;
					pre_cur->next = cur;
				}

			}
			return dumy->next;
		}

	
};

