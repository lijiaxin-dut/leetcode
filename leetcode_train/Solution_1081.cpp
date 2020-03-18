#include<string>
#include<vector>

using namespace std;




class Solution {
public:
	string smallestSubsequence(string text) {
		vector<int>count(26, 0);
		vector<bool>visited(26, false);

		for (auto &c : text)
			count[c - 'a']++;

		string rs;
		for (int i = 0; i<text.size(); i++) {
			count[text[i] - 'a']--;
			if (visited[text[i] - 'a'] == true)
				continue;
			while (!rs.empty() && text[i]<rs.back() && count[rs.back() - 'a']>0) {
				visited[rs.back() - 'a'] = false;
				rs.pop_back();
			}
			visited[text[i] - 'a'] = true;
			rs.push_back(text[i]);
		}
		return rs;



	}
};