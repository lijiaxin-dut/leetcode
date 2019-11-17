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



class Solution_1019 {
	int get_length(ListNode *head) {
		int l = 0;
		while (head != nullptr) {
			head = head->next;
			l++;
		}
		return l;
	}
public:
	vector<int> nextLargerNodes(ListNode* head) {
		stack<pair<ListNode *, int>>st;
		int length = get_length(head);
		vector<int>rs(length, 0);
		int current_index = 0;
		while (head) {
			if (st.empty() || st.top().first->val >= head->val) {
				st.push(make_pair(head, current_index++));
				head = head->next;
			}
			else {
				auto last_node = st.top();
				st.pop();
				rs[last_node.second] = head->val;
			}
		}
		return rs;
	}
};