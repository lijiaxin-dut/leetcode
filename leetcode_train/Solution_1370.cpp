#include<unordered_map>
#include<string>

using namespace std;

//统计每个字符的次数
//只包含小写字母
//依次从a->z 和从z->a遍历

class Solution {
public:
	string sortString(string ss) {
		unordered_map<char, int>m;
		for (auto &one_c : ss)
			m[one_c]++;
		string rs;
		while (rs.size()<ss.size()) {
			for (char i = 'a'; i <= 'z'; i++) {
				if (m[i]>0) {
					rs += i;
					m[i]--;
				}
			}
			for (char i = 'z'; i >= 'a'; i--) {
				if (m[i]>0) {
					rs += i;
					m[i]--;
				}
			}
		}
		return rs;

	}
};