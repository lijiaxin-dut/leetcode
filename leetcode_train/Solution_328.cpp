#include"ListNode.h"
#include<algorithm>

using namespace std;
//
//Given a singly linked list, group all odd nodes together followed by the even nodes.Please note here we are talking about the node number and not the value in the nodes.
//
//You should try to do it in place.The program should run in O(1) space complexity and O(nodes) time complexity.
//
//Example 1:
//
//Input: 1->2->3->4->5->NULL
//	Output : 1->3->5->2->4->NULL

//声明新的辅助变量，将奇数位置和偶数位置分别放入对应的链表中，最后合并即可


class Solution_328 {
public:
	ListNode* oddEvenList(ListNode* head) {
		ListNode *odd = new ListNode(-1);//奇数
		ListNode *even = new ListNode(-1);
		ListNode *back_odd_head = odd;
		ListNode *back_even_head = even;
		int current_index = 0;
		while (head != NULL) {
			if (current_index % 2 == 1)
			{
				odd->next = head;
				odd = odd->next;
			}
			else {
				even->next = head;
				even = even->next;
			}
			current_index++;
			head = head->next;
		}
		even->next = back_odd_head->next;
		odd->next = NULL;
		return back_even_head->next;

	}
};