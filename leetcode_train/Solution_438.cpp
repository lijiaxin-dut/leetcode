#include<vector>

using namespace std;

//Given a string s and a non - empty string p, find all the start indices of p's anagrams in s.
//
//Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20, 100.
//
//The order of output does not matter.
//
//Example 1:
//
//Input:
//s: "cbaebabacd" p : "abc"
//
//	Output :
//	[0, 6]
//
//   Explanation :
//	   The substring with start index = 0 is "cba", which is an anagram of "abc".
//	   The substring with start index = 6 is "bac", which is an anagram of "abc".
//

//固定滑动窗口的大小，不断的向右滑动，每次滑动之后，比较hasp_map是否相同

class Solution_438 {
public:
	vector<int> findAnagrams(string s, string p) {
		if (s.empty() || p.size()>s.size())
			return vector<int>();
		vector<int>dynamic_hash_map(26);
		vector<int>p_hash_map(26);

		for (int i = 0; i<p.size() && i<s.size(); i++) {
			p_hash_map[p[i] - 'a']++;
			dynamic_hash_map[s[i] - 'a']++;
		}
		vector<int>rs;
		if (p_hash_map == dynamic_hash_map)
			rs.push_back(0);
		int left = 0;
		for (int i = p.size(); i<s.size(); i++) {
			dynamic_hash_map[s[left] - 'a']--;
			dynamic_hash_map[s[i] - 'a']++;
			left++;
			if (p_hash_map == dynamic_hash_map)
				rs.push_back(left);

		}
		return rs;


	}
};