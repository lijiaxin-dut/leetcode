#include<vector>
#include<string>
#include<iostream>
using namespace std;



//Design a data structure that supports the following two operations :
//
//void addWord(word)
//bool search(word)
//search(word) can search a literal word or a regular expression string containing 
//only letters a - z or .
//.means it can represent any one letter.

//插入与字典树相同
//查找时，增加dfs搜索
//遇到.时，向后搜索所有不为空的子树
//只要找到一个，就返回即可


class tie_tree {
public:
	struct node {
		bool is_word = false;
		vector<node*>next;
		node() {
			next.resize(26, NULL);
		}
	};
	node*root;
	tie_tree() {
		root = new node();
	}
	void insert(string word) {
		node*head = root;
		for (int i = 0; i<word.size(); i++) {
			int index = word[i] - 'a';
			if (head->next[index] == NULL)
				head->next[index] = new node();
			head = head->next[index];
		}
		head->is_word = true;
	}
	bool search(string word) {
		bool find = false;
		search(root, word, 0, find);
		return find;
	}
	void search(node *x, string &word, int index, bool &find) {
		if (index == word.size()) {
			if (x->is_word == true)
				find = true;
			return;
		}
		if (find == true)
			return;
		if (word[index] == '.') {
			for (int j = 0; j<26 && find == false; j++) {
				if (x->next[j] != NULL) {
					search(x->next[j], word, index + 1, find);
				}
			}
			return;
		}
		else {
			if (x->next[word[index] - 'a'] != NULL) {
				search(x->next[word[index] - 'a'], word, index + 1, find);
			}

		}
	}

};

class WordDictionary {
	tie_tree t;
public:
	/** Initialize your data structure here. */
	WordDictionary() {

	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		t.insert(word);
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return t.search(word);
	}
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary* obj = new WordDictionary();
* obj->addWord(word);
* bool param_2 = obj->search(word);
*/

//int main() {
//	WordDictionary d;
//	cout<<d.search("a");
//}
