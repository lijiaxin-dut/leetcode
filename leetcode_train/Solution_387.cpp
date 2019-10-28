#include<string>
#include<vector>

using namespace std;

//Given a string, find the first non - repeating character in it and return it's index. If it doesn't exist, return -1.
//
//Examples:
//
//s = "leetcode"
//return 0.
//
//s = "loveleetcode",
//return 2.

//ʹ�����������¼ÿ����ĸ��һ�γ��ֵ�λ�ú����һ�γ��ֵ�λ��
//��ǰ������
//��һ�γ��ֵ�λ�ú����һ�γ��ֵ�λ����ͬ�����Ǵ�


class Solution_387 {
public:
	int firstUniqChar(string s) {
		vector<int>first_appear(26, -1);
		vector<int>last_appear(26, -1);
		int n = s.size();
		for (int i = 0; i<n; i++) {
			if (first_appear[s[i] - 'a'] == -1)
				first_appear[s[i] - 'a'] = i;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (last_appear[s[i] - 'a'] == -1)
				last_appear[s[i] - 'a'] = i;
		}
		for (int i = 0; i<n; i++) {
			int index = s[i] - 'a';
			if (first_appear[index] == last_appear[index] && first_appear[index] != -1)
				return i;
		}
		return -1;
	}
};

