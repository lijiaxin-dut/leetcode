#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;
//
//Given a 2D board and a list of words from the dictionary, find all words in the board.
//
//Each word must be constructed from letters of sequentially adjacent cell, 
//where "adjacent" cells are those horizontally or vertically neighboring.
//The same letter cell may not be used more than once in a word.


//用所有要插找的单词，构成一个字典树
//board的每一个位置开始，遍历整个board
//如果当前前缀在字典树不存在，可以剪枝
//如果当前结果在字典树中，就加到结果中


class Solution_212 {
	class Node {
	public:
		bool is_word = false;
		vector<Node*>next;
		Node() {
			next.resize(26, nullptr);
		}
	};
	class Trie {
		
	public:
		Node *root;
		/** Initialize your data structure here. */
		Trie() {
			root = new Node();
		}

		/** Inserts a word into the trie. */
		void insert(string word) {
			Node *cur = root;
			for (int i = 0; i<word.size(); i++) {
				auto &one_char = word[i];
				int index = one_char - 'a';
				if (cur->next[index] == nullptr) {
					cur->next[index] = new Node();
				}
				cur = cur->next[index];
				if (i == word.size() - 1) {
					cur->is_word = true;
				}
			}

		}

		/** Returns if the word is in the trie. */
		bool search(string word) {
			Node *cur = root;
			for (int i = 0; i<word.size(); i++) {
				auto &one_char = word[i];
				int index = one_char - 'a';
				if (cur->next[index] == nullptr)
					return false;
				cur = cur->next[index];
				if (i == word.size() - 1) {
					if (cur->is_word == true)
						return true;
				}
			}
			return false;
		}

		/** Returns if there is any word in the trie that starts with the given prefix. */
		bool startsWith(string prefix) {
			Node *cur = root;
			for (int i = 0; i<prefix.size(); i++) {
				auto &one_char = prefix[i];
				int index = one_char - 'a';
				if (cur->next[index] == nullptr)
					return false;
				cur = cur->next[index];
			}
			return true;
		}
	};
	set<string>rs;
	Trie trie;
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		int m = board.size();
		if (m == 0 || words.empty())
			return{};
		int n = board[0].size();
		for (auto &word : words)
			trie.insert(word);
		vector<vector<bool>>mark(m, vector<bool>(n, false));
		string temp;
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				find(temp, i, j, mark, board);
			}
		}

		return{ rs.begin(),rs.end() };
	}
	void find(string &word, int row, int col, vector<vector<bool>>&mark, vector<vector<char>>&board) {
		//越界,或者已经访问
		if (row<0 || row >= board.size() || col<0 || col >= board[0].size() || mark[row][col] == true)
			return;
		word += board[row][col];
		if (trie.startsWith(word) == false) {
			word.pop_back();
			return;
		}
		if (trie.search(word) == true) {
			rs.insert(word);
		}
		mark[row][col] = true;
		find(word, row + 1, col, mark, board);
		find(word, row, col + 1, mark, board);
		find(word, row - 1, col, mark, board);
		find(word, row, col - 1, mark, board);
		mark[row][col] = false;
		word.pop_back();
		return;

	}
};