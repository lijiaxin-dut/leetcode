#include<unordered_map>
#include<unordered_set>
#include<vector>

using namespace std;

//生成所有字典中的单词的广义邻居

//对于搜索的单词，如果存在两个广义邻居，则说明一定存在
//如果只存在一个广义邻居，则要当前单词是否在列表中
class MagicDictionary {
public:
	unordered_set<string>words;
	unordered_map<string, int>count;
	/** Initialize your data structure here. */
	MagicDictionary() {

	}

	vector<string>generakuzed_neighbors(string &word) {
		vector<string>ans;
		for (int i = 0; i < word.size(); ++i) {
			char letter = word[i];
			word[i] = '*';
			ans.push_back(word);
			word[i] = letter;
		}
		return ans;
	}
	void buildDict(vector<string> dictionary) {
		for (auto word : dictionary) {
			words.insert(word);
			for (auto nei : generakuzed_neighbors(word)) {
				count[nei]++;
			}
		}
	}

	bool search(string searchWord) {
		for (auto nei : generakuzed_neighbors(searchWord)) {
			int c = count[nei];
			if (c > 1 || (c == 1 && words.find(searchWord) == words.end()))
				return true;
		}
		return false;
	}
};


/**
* Your MagicDictionary object will be instantiated and called as such:
* MagicDictionary* obj = new MagicDictionary();
* obj->buildDict(dictionary);
* bool param_2 = obj->search(searchWord);
*/

