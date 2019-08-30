#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//A string S of lowercase letters is given. 
//We want to partition this string into as many parts as possible so that each letter appears 
//in at most one part, and return a list of integers representing the size of these parts.

//Example 1:
//Input: S = "ababcbacadefegdehijhklij"
//	Output : [9, 7, 8]
//	Explanation :
//	The partition is "ababcbaca", "defegde", "hijhklij".
//	This is a partition so that each letter appears in at most one part.
//	A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.


class Solution_763 {
public:
	vector<int> partitionLabels(string S) {
		if (S.size() <= 1)
			return vector<int>(S.size());
		//最后一次出现的位置
		vector<int>last_appear(26, -1);
		for (int i = 0; i < S.size(); i++) {
			last_appear[S[i] - 'a'] = i;
		}
		int current_index = 0;
		vector<int>rs;
		while (current_index < S.size()) {
			auto current_letter = S[current_index];
			int current_letter_last_index = last_appear[current_letter - 'a'];
			//不断的将最后一次出现的位置后移，直至不能移动
			for (int i = current_index; i <= current_letter_last_index; i++) {
				current_letter_last_index = max(current_letter_last_index, last_appear[S[i] - 'a']);
			}
			rs.push_back(current_letter_last_index - current_index + 1);
			current_index = current_letter_last_index + 1;
		}
		return rs;
	}
};