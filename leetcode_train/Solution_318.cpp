#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std; 
//
//Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.You may assume that each word will contain only lower case letters.If no such two words exist, return 0.
//
//Example 1:
//
//Input: ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
//	Output : 16
//	Explanation : The two words can be "abcw", "xtfn".

// '=='的优先级高于 '&'

//用int作mark,标记哪些字母出现

//mark |= 1 << (one_char - 'a');

class Solution_318 {
public:
	int maxProduct(vector<string>& words) {
		vector<long>hash_map;
		for (auto &one_string : words) {
			long mark = 0;
			for (auto &one_char : one_string) {
				mark |= 1 << (one_char - 'a');
			}
			hash_map.push_back(mark);
		}
		int rs = 0;
		for (int i = 0; i<hash_map.size(); i++) {
			for (int j = i + 1; j<hash_map.size(); j++) {
				if ((hash_map[i] & hash_map[j]) == 0) {
					rs = max(rs, (int)words[i].size()*(int)words[j].size());
				}

			}
		}
		return rs;
	}
};

//int main() {
//	Solution_318 s;
//	vector<string>sss{ "abcw","baz","foo","bar","xtfn","abcdef" };
//	s.maxProduct(sss);
//}