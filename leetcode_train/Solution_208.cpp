#include<vector>
#include<string>
#include<iostream>
using namespace std;
//
//Implement a trie with insert, search, and startsWith methods.
//
//Example:
//
//Trie trie = new Trie();
//
//trie.insert("apple");
//trie.search("apple");   // returns true
//trie.search("app");     // returns false
//trie.startsWith("app"); // returns true
//trie.insert("app");
//trie.search("app");     // returns true

//1. ���ڵ㲻�����ַ��������ڵ�����ÿ���ڵ�ֻ����һ���ַ���
//
//2. �Ӹ��ڵ㵽ĳһ���ڵ㣬·���Ͼ������ַ�����������Ϊ�ýڵ��Ӧ���ַ�����
//
//3. ÿ���ڵ�������ӽڵ�������ַ�������ͬ��

//ÿ���ڵ���26���ӽڵ�
//��Ҫ���ÿ���ڵ��Ƿ���һ�����ʵ��յ�




class Trie {
	struct node {
		bool is_word = false;
		vector<node*>next;
		node() {
			next.resize(26, NULL);
		}
	};
public:
	node *root;
	/** Initialize your data structure here. */
	Trie() {
		root = new node();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		node *head = root;
		for (int i = 0; i < word.size(); i++) {
			if (head->next[word[i]-'a'] == NULL) {
				head->next[word[i]-'a'] = new node();
				head = head->next[word[i] - 'a'];
			}
			else {
				head = head->next[word[i] - 'a'];
			}
		}
		head->is_word = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		node *head = root;
		for (int i = 0; i < word.size(); i++) {
			if (head->next[word[i] - 'a'] == NULL)
				return false;
			head = head->next[word[i] - 'a'];
		}
		return head->is_word;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		node *head = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (head->next[prefix[i] - 'a'] == NULL)
				return false;
			head = head->next[prefix[i] - 'a'];
		}
		return true;
	}
	
};

/**
* Your Trie object will be instantiated and called as such:
* Trie* obj = new Trie();
* obj->insert(word);
* bool param_2 = obj->search(word);
* bool param_3 = obj->startsWith(prefix);
*/

