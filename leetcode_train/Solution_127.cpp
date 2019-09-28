#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<memory>
#include<unordered_map>
#include<set>
#include<queue>
#include<unordered_set>

using namespace std;


//dfs��ʱ

//bfs
//��һ������
//�ҳ����иı�һ�ο��Եõ��ĵ��ʣ����ҳ�����dict��
//����Щ���ʴ�dict��ɾ��

//���ϵ��ظ���ֱ���ҵ�endWord

//һ��һ��ı����������ظ��������µĵ��ʺ󣬿���ֱ����dict�еĵ���ɾ��
//��Ϊ�����������һ��


class Solution_127 {
	int different_size(string a, string b) {
		int diff_size = 0;
		for (int i = 0; i<a.size(); i++) {
			if (a[i] != b[i])
				diff_size++;
		}

		return diff_size;
	}
public:

	int ladderLength_bfs(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		queue<string> todo;
		todo.push(beginWord);
		int rs = 1;
		while (!todo.empty()) {
			int n = todo.size();
			for (int i = 0; i<n; i++) {
				string word = todo.front();
				todo.pop();
				if (word == endWord)
					return rs;
				for (int j = 0; j<word.size(); j++) {
					char c = word[j];
					for (char k = 'a'; k <= 'z'; k++) {
						word[j] = k;
						if (dict.find(word) != dict.end()) {
							dict.erase(word);
							todo.push(word);
						}
					}
					word[j] = c;
				}
			}
			rs++;
		}
		return 0;

	}


	int ladderLength_dfs(string beginWord, string endWord, vector<string>& wordList) {
		int n = wordList.size();
		vector<bool>mark(n, false);
		int rs = INT_MAX;
		help(n, rs, wordList, mark, 0, beginWord, endWord);
		return rs == INT_MAX ? 0 : rs + 1;

	}
	void help(int n, int &rs, vector<string>& wordList, vector<bool>&mark, int change_number, string &current_world, string &end_world) {
		if (current_world == end_world) {
			rs = min(change_number, rs);
			return;
		}
		for (int i = 0; i<n; i++) {
			if (mark[i] == false) {
				//ֻ��һ����ͬ
				if (different_size(current_world, wordList[i]) == 1) {
					mark[i] = true;
					help(n, rs, wordList, mark, change_number + 1, wordList[i], end_world);
					mark[i] = false;
				}
			}
		}
	}
};