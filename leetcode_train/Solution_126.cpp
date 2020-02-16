#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

//Given two words(beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
//
//Only one letter can be changed at a time
//Each transformed word must exist in the word list.Note that beginWord is not a transformed word.
//Note:
//
//Return an empty list if there is no such transformation sequence.
//All words have the same length.
//All words contain only lowercase alphabetic characters.
//You may assume no duplicates in the word list.
//You may assume beginWord and endWord are non - empty and are not the same.

//根据路径进行BFS
//剪枝：
//上一层所有出现的值，都不会在后面的level中出现
//a->b>->endWord
//不会存在b->a->endWord,因为可以直接由b到endWord

class Solution_126 {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		queue<vector<string>> todo;
		todo.push(vector<string>{beginWord});
		bool is_find = false;
		vector<vector<string>>rs;
		unordered_set<string>visited;
		while (!todo.empty()) {
			for (auto c : visited) {
				dict.erase(c);
			}
			int n = todo.size();
			for (int i = 0; i<n; i++) {
				auto cur_word_path = todo.front();
				string word = cur_word_path.back();
				todo.pop();
				for (int j = 0; j<word.size(); j++) {
					char c = word[j];
					for (char k = 'a'; k <= 'z'; k++) {
						word[j] = k;
						if (dict.find(word) != dict.end()) {
							if (word == endWord) {
								is_find = true;
								rs.push_back(cur_word_path);
								rs.back().push_back(word);
							}
							else {
								todo.push(cur_word_path);
								todo.back().push_back(word);
								visited.insert(word);
							}

						}
					}
					word[j] = c;
				}
			}
			if (is_find == true)
				break;
		}
		return rs;

	}
};
