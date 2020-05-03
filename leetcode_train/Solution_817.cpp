#include"ListNode.h"
#include<vector>
#include<unordered_set>

using namespace std;

//将G放到集合中，方便查找
//遍历链表，如果当前结果在set中，就继续向后遍历，直至不在set中
//使用标记位记录当前轮次是否有在set中的节点




class Solution_817 {
public:
	int numComponents(ListNode* head, vector<int>& G) {
		unordered_set<int>s(G.begin(), G.end());
		int rs = 0;
		while (head) {
			bool find = false;
			while (head&&s.count(head->val)) {
				head = head->next;
				find = true;
			}
			if (find)
				rs++;
			else
				head = head->next;
		}
		return rs;
	}
};