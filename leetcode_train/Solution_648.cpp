#include<vector>
#include<string>
#include<sstream>
#include<unordered_set>
#include<algorithm>
using namespace std;

//在英语中，我们有一个叫做 词根(root)的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。
//现在，给定一个由许多词根组成的词典和一个句子。你需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。
//你需要输出替换之后的句子。
//
//
//示例 1：
//
//输入：dictionary = ["cat", "bat", "rat"], sentence = "the cattle was rattled by the battery"
//输出："the cat was rat by the bat"

//1.穷绝所有的前缀和
//2.所有的词根构成一个前缀树
//	然后搜索前缀树

class Solution {
public:
	string replaceWords(vector<string>& dictionary, string sentence) {
		unordered_set<string>s(dictionary.begin(), dictionary.end());
		vector<int>word_length;
		for (auto &i : s) {
			word_length.push_back(i.size());
		}
		sort(word_length.begin(), word_length.end());
		stringstream ss(sentence);
		string rs;
		string one_word;
		while (getline(ss, one_word, ' ')) {
			bool change = false;
			for (auto length : word_length) {
				if (one_word.size()>length) {
					string temp = one_word.substr(0, length);
					if (s.count(temp)) {
						rs += temp + " ";
						change = true;
						break;
					}
				}
			}
			if (change == false) {
				rs += one_word + " ";
			}
		}
		if (!rs.empty())
			rs.pop_back();
		return rs;
	}
};