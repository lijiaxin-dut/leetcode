#include<string>

using namespace std;

//Given an input string(s) and a pattern(p), implement regular expression matching with support for '.' and '*'.
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//The matching should cover the entire input string(not partial).
//
//Note:
//
//s could be empty and contains only lowercase letters a - z.
//p could be empty and contains only lowercase letters a - z, and characters like . or *.


//���pΪ�գ��ж�s�Ƿ�Ϊ��
//���p�ĳ���Ϊ1���ж�s�ĳ����Ƿ�Ϊ1������ƥ��
//���p�ĳ���>1,�жϵڶ�λ�Ƿ���*������*����˳��ƥ��
//����ڶ�λ��*
//��Ҫʹ��ѭ���ж�
//ȥ��p��ǰ��λ����s����ƥ�䣬���赱ǰ�ַ�����0��
//Ȼ��ȥ��s�����ַ�����Ϊ*���Գ��ֶ�Σ�����Ҫȥ��
//ѭ���������ж�isMatch(s, p.substr(2))

//���ص��õݹ麯��ƥ��s��ȥ��ǰ�����ַ���p�Ľ��
//����ô����ԭ���Ǵ����Ǻ��޷�ƥ������ݣ����� s="ab", p="a*b"��
//ֱ�ӽ��� while ѭ�������Ƿ��� "ab" �� "b" ��ƥ�䣬����s��� "b"��
//��ô��ʱ����ѭ���󣬾͵����� return ���Ƚ� "b" �� "b" �ˣ����� true��
//�پٸ����ӣ����� s="", p="a*"������sΪ�գ���������κε� if �� while��
//ֻ�ܵ����� return ���Ƚ��ˣ����� true����ȷ


class Solution_10 {
public:
	bool isMatch(string s, string p) {
		if (p.empty())
			return s.empty();
		if (p.size() == 1)
			return s.size() == 1 && (s[0] == p[0] || p[0] == '.');
		if (p[1] != '*') {
			if (s.empty())
				return false;
			return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
		while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
			if (isMatch(s, p.substr(2)))
				return true;
			s = s.substr(1);
		}
		return isMatch(s, p.substr(2));

	}
};