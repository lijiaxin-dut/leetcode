#include<vector>
#include<unordered_map>

using namespace std;

//All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//
//Write a function to find all the 10 - letter - long sequences(substrings) that occur more than once in a DNA molecule.
//
//Example :
//
//	Input : s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
//
//	Output : ["AAAAACCCCC", "CCCCCAAAAA"]

//遍历所有的字串放入到hash_map中，找到出现多次的即可


class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<string, int>hash_map;
		for (int i = 0; i <= int(s.size()) - 10; i++) {
			hash_map[s.substr(i, 10)]++;
		}
		vector<string>rs;
		for (auto &one_sub : hash_map) {
			if (one_sub.second>1)
				rs.push_back(one_sub.first);
		}
		return rs;
	}
};