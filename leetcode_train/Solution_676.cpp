#include<unordered_map>
#include<unordered_set>
#include<vector>

using namespace std;

//���������ֵ��еĵ��ʵĹ����ھ�

//���������ĵ��ʣ�����������������ھӣ���˵��һ������
//���ֻ����һ�������ھӣ���Ҫ��ǰ�����Ƿ����б���
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

