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
//tail表示链表的尾部节点
//cur表示当前判断的节点
//pre表示cur之前的节点

//单独考虑一个节点或者空链表
//最后处理尾部重复的情况，最后cur为空

class Solution_82 {
public:

	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode *dumy = new ListNode(-1);
		dumy->next = head;
		ListNode *cur = head->next;
		ListNode *pre = head;
		ListNode *tail = dumy;//当前的尾节点
		while (cur) {
			//有相等的值时，就向后移动
			if (cur->val == pre->val) {
				pre = pre->next;
				cur = cur->next;
			}
			//当值不相等时，判断tail->next与pre是否相等，
			//即判断pre是否在答案中
			//若tail->next != pre 说明pre不在答案中，将tail->next指向cur
			else if (tail->next != pre&&cur->val != pre->val) {
				tail->next = cur;
				pre = cur;
				cur = cur->next;
			}
			//若tail->next == pre 说明pre在答案中，
			//即tail,pre,cur是连续的三个指针
			//将pre插入答案中
			
			else if (tail->next == pre&&cur->val != pre->val) {
				tail = pre;
				pre = pre->next;
				cur = cur->next;
			}
		}
		//判断最后是否存在重复的节点，因为pre指向最后一个节点，cur为空，
		if (tail->next != pre)
			tail->next = nullptr;
		//注意将链表尾部置空
		return dumy->next;
	}
};