#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<memory>
#include<unordered_map>
#include<set>
#include<queue>

using namespace std;


//
//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
//Return a deep copy of the list.


//使用hash_map标记哪些点已经申请过空间
//依次迭代即可



class Node_l {
public:
	int val;
	Node_l* next;
	Node_l* random;

	Node_l() {}

	Node_l(int _val, Node_l* _next, Node_l* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};

class Solution_136 {
public:
	Node_l* copyRandomList(Node_l* head) {
		if (head == NULL)
			return NULL;
		Node_l* back_head = head;
		unordered_map<Node_l*, Node_l*>hash_map;
		while (head != NULL) {
			Node_l *new_node;
			if (hash_map.find(head) == hash_map.end()) {
				new_node = new Node_l(head->val,NULL,NULL);
				hash_map[head] = new_node;
			}
			else {
				new_node = hash_map[head];
			}
			if (head->next != NULL) {
				if (hash_map.find(head->next) == hash_map.end()) {
					Node_l *new_next_node = new Node_l(head->next->val,NULL,NULL);
					new_node->next = new_next_node;
					hash_map[head->next] = new_next_node;
				}
				else {
					new_node->next = hash_map[head->next];
				}
			}
			if (head->random != NULL) {
				if (hash_map.find(head->random) == hash_map.end()) {
					Node_l * new_random_node = new Node_l(head->random->val,NULL,NULL);
					new_node->random = new_random_node;
					hash_map[head->random] = new_random_node;
				}
				else {
					new_node->random = hash_map[head->random];
				}
			}
			head = head->next;
		}
		return hash_map[back_head];

	}
};
