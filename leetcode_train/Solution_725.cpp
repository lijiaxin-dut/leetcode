#include"ListNode.h"
#include<vector>

using namespace std;


//Given a(singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".
//
//The length of each part should be as equal as possible : no two parts should have a size differing by more than 1. This may lead to some parts being null.
//
//The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal parts occurring later.
//
//Return a List of ListNode's representing the linked list parts that are formed.
//
//Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]


//先计算长度，然后分情况讨论

//计算每一组的个数

//然后按顺序划分到每一组，上一组的尾部与下一组的头部要断开

class Solution {
	int get_length(ListNode*node) {
		int l = 0;
		while (node) {
			l++;
			node = node->next;
		}
		return l;
	}
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		int length = get_length(root);
		vector<ListNode*>rs(k, nullptr);
		int n = length / k;//每一组相等的长度
		int r = length%k;//前r组每组多一个节点
		for (int i = 0; i<k&&root != nullptr; i++, r--) {
			rs[i] = root;
			ListNode*pre = nullptr;
			for (int j = 0; j<n + (r>0); j++) {
				pre = root;
				root = root->next;
			}
			pre->next = nullptr;
		}
		return rs;
	}
};