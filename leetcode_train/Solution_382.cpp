#include<random>
#include"ListNode.h"


//水塘抽样

//维持一个大小为1的水塘

//遇到第k个数时，随机产生[0,k]的数
//如果产生的数为0 ，则更新水塘


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
	ListNode *head;
public:
	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) :head(head) {

	}

	/** Returns a random node's value. */
	int getRandom() {
		int res = head->val;
		int i = 2;
		ListNode *cur = head->next;
		while (cur) {
			int j = rand() % i;
			if (j == 0)
				res = cur->val;
			++i;
			cur = cur->next;
		}
		return res;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution* obj = new Solution(head);
* int param_1 = obj->getRandom();
*/