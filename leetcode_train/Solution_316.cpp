#include<vector>
#include<memory>
#include<iostream>
#include<string>
using namespace std;



//Given a string which contains only lowercase letters, remove duplicate letters so that every letter appears once and only once.You must make sure your result is the smallest in lexicographical order among all possible results.
//
//Example 1:
//
//Input: "bcabc"
//	Output : "abc"
//	Example 2 :
//
//	Input : "cbacdcbc"
//	Output : "acdb"

//visited标记当前字符是否已经在结果中，跳过已经访问过的
//count纪律剩余字母出现的次数

//如果当前字符<rs.back()  &&  rs.back()在后面出现过
//则删除rs.back()



class Solution_315 {
public:
	string removeDuplicateLetters(string s) {
		vector<int>count(26, 0);
		vector<bool>visited(26, false);
		string rs;
		for (int i = 0; i<s.size(); i++) {
			count[s[i] - 'a']++;
		}
		for (int i = 0; i<s.size(); i++) {
			count[s[i] - 'a']--;
			if (visited[s[i] - 'a'] == true)
				continue;
			while (!rs.empty() && (s[i]<rs.back() && count[rs.back() - 'a']>0)) {
				visited[rs.back() - 'a'] = false;
				rs.pop_back();
			}
			visited[s[i] - 'a'] = true;
			rs += s[i];
		}
		return rs;


	}
};
