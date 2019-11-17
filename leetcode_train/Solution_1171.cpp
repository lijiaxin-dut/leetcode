#include"ListNode.h"
#include<unordered_map>

using namespace std;

//Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
//
//After doing so, return the head of the final linked list.You may return any such answer.
//
//
//
//(Note that in the examples below, all sequences are serializations of ListNode objects.)
//
//Example 1:
//
//Input: head = [1, 2, -3, 3, 1]
//	Output : [3, 1]
//	Note : The answer[1, 2, 1] would also be accepted.
//	Example 2 :
//
//	Input : head = [1, 2, 3, -3, 4]
//	Output : [1, 2, 4]
//	Example 3 :
//
//	Input : head = [1, 2, 3, -3, -2]
//	Output : [1]

//1.遍历所有的组合，O(n^2)
//2.前缀和
//
//遍历链表，保存所有的前缀和，如果某一个前缀和出现过，则说明有sum为0的片段

// a b c d e f  g h j
//如果pre_sum[a...f]==pre_sum[a...j]
//则sum(g,h,j)=0

//将这三个节点删除
//并且将g h对应的前缀和删除



class Solution_1171 {
public:


	ListNode* removeZeroSumSublists_pre_sum(ListNode* head) {
		ListNode *dumy = new ListNode(0);
		dumy->next = head;
		unordered_map<int, ListNode*>m;
		auto cur = dumy;
		int prefix_sum = 0;
		while (cur) {
			prefix_sum += cur->val;
			if (m.count(prefix_sum)) {
				cur = m[prefix_sum]->next;
				int p = prefix_sum + cur->val;
				while (p != prefix_sum) {
					m.erase(p);
					cur = cur->next;
					p += cur->val;
				}
				m[prefix_sum]->next = cur->next;
			}
			else {
				m[prefix_sum] = cur;
			}
			cur = cur->next;
		}

		return dumy->next;

	}

	ListNode* removeZeroSumSublists(ListNode* head) {
		ListNode *dumy = new ListNode(0);
		dumy->next = head;
		for (auto cur_head = dumy; cur_head != nullptr;) {
			auto pre = cur_head;
			int sum = 0;
			for (auto next_node = cur_head->next; next_node != nullptr; next_node = next_node->next) {
				sum += next_node->val;
				if (sum == 0) {
					pre->next = next_node->next;
					continue;
				}
			}
			cur_head = cur_head->next;
		}
		return dumy->next;

	}
};