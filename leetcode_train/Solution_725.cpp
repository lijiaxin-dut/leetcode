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

class Solution_725 {
	int get_length(ListNode *head) {
		int l = 0;
		while (head != nullptr) {
			head = head->next;
			l++;
		}
		return l;
	}
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		int length = get_length(root);
		vector<ListNode*>rs(k, nullptr);
		if (k >= length) {
			int cur_index = 0;
			while (root != nullptr) {
				rs[cur_index++] = root;
				auto back = root->next;
				root->next = nullptr;
				root = back;
			}
		}
		else {
			int each_group_equal_size = length / k;
			int over_size = length%k;
			vector<int>each_size(k, each_group_equal_size);
			for (int i = 0; i<k&&over_size>0; i++) {
				each_size[i]++;
				over_size--;
			}
			for (int i = 0; i<k; i++) {
				rs[i] = root;
				int cur_size = 1;
				while (cur_size++<each_size[i]) {
					root = root->next;
				}
				auto pre = root;
				root = root->next;
				pre->next = nullptr;
			}
		}
		return rs;

	}
};