#include<string>

using namespace std;

//�ַ�����ת�����������ַ���s1��s2�����д������s2�Ƿ�Ϊs1��ת���ɣ����磬waterbottle��erbottlewat��ת����ַ�������

//ƴ��s1+s1
//�ж�s2�Ƿ�������

class Solution {
public:
	bool isFlipedString(string s1, string s2) {
		if (s1.size() != s2.size())
			return false;
		if (s1 == s2)
			return true;
		string new_string = s2 + s2;
		if (strstr(new_string.c_str(), s1.c_str()))
			return true;
		else
			return false;
	}
};