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
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *dumy = new ListNode(INT_MIN);
		dumy->next = head;
		ListNode*pre = head;
		head = head->next;
		while (head != NULL) {
			pre->next = head->next;
			//插入到h1后面的位置，需要记录h1的pre节点
			for (ListNode *h1 = dumy, *inside_pre = dumy; h1 != pre->next; inside_pre = h1, h1 = h1->next) {
				if (head->val < h1->val) {
					inside_pre->next = head;
					head->next = h1;
					break;
				}
			}
			//这种情况下位置不发生变化
			if (head->next == pre->next) {
				pre->next = head;
				pre = head;
				head = head->next;
			}
			else
				head = pre->next;
		}
		return dumy->next;

	}
};

//int main() {
//	Solution_147 s;
//	ListNode *n1 = new ListNode(-1);
//	ListNode *n2 = new ListNode(5);
//	n1->next = n2;
//	ListNode *n3 = new ListNode(3);
//	n2->next = n3;
//	ListNode *n4 = new ListNode(4);
//	n3->next = n4;
//	s.insertionSortList(n1);
//}