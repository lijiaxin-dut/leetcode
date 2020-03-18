#include<unordered_map>
#include<string>

using namespace std;

//ͳ��ÿ���ַ��Ĵ���
//ֻ����Сд��ĸ
//���δ�a->z �ʹ�z->a����

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