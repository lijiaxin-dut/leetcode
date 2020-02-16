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

//1.
//使用hash_map标记哪些点已经申请过空间
//依次迭代即可

//2.
//使用常数空间
//a.遍历原始链表，拷贝该节点，并将拷贝节点插入到该节点后面
//b.修改random指针
//c.从整体链表中分离出两个链表

class Node_l {
public:
	int val;
	Node_l* next;
	Node_l* random;

	Node_l() {}
	Node_l(int c) {
		val = c;
	}
	Node_l(int _val, Node_l* _next, Node_l* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};

class Solution_136 {
public:
	Node_l* copyRandomList_constmemory(Node_l* head) {
		Node_l *iter = head;
		//每个节点后面新插入一个当前节点的拷贝
		while (iter) {
			Node_l *new_node = new Node_l(iter->val);
			auto next = iter->next;
			iter->next = new_node;
			new_node->next = next;
			iter = next;
		}
		//修改random指针
		iter = head;
		while (iter) {
			if (iter->random)
				iter->next->random = iter->random->next;
			iter = iter->next->next;
		}
		//从整体链表中取出原链表与新链表
		Node_l *dumy = new Node_l(0);
		Node_l *new_head = dumy;
		iter = head;
		while (iter) {
			new_head->next = iter->next;
			iter->next = iter->next->next;
			new_head = new_head->next;
			iter = iter->next;
		}
		return dumy->next;

	}
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
