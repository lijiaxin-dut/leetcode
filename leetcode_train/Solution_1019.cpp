#include"ListNode.h"
#include<stack>
#include<vector>

using namespace std;

//We are given a linked list with head as the first node.Let's number the nodes in the list: node_1, node_2, node_3, ... etc.
//
//Each node may have a next larger value : for node_i, next_larger(node_i) is the node_j.val such that j > i, node_j.val > node_i.val, and j is the smallest possible choice.If such a j does not exist, the next larger value is 0.
//
//Return an array of integers answer, where answer[i] = next_larger(node_{ i + 1 }).
//
//Note that in the example inputs(not outputs) below, arrays such as[2, 1, 5] represent the serialization of a linked list with a head node value of 2, second node value of 1, and third node value of 5.

//使用stack保存指针，是一个递减栈
//当遇到比栈顶元素大的nums[i]时，就找到了第一个大于栈顶元素的位置


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
	vector<int>get_nums(ListNode*head) {
		vector<int>nums;
		while (head) {
			nums.push_back(head->val);
			head = head->next;
		}
		return nums;
	}
public:
	vector<int> nextLargerNodes(ListNode* head) {
		if (head == nullptr)
			return{};
		vector<int>nums = get_nums(head);
		int n = nums.size();
		vector<int>rs(n, 0);
		stack<int>s;
		for (int i = 0; i<n; i++) {
			while (!s.empty() && nums[i]>nums[s.top()]) {
				rs[s.top()] = nums[i];
				s.pop();
			}
			s.push(i);
		}
		return rs;
	}
};