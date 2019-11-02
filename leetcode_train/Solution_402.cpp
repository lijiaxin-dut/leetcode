#include<string>

using namespace std;

//Given a non - negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
//
//Note:
//The length of num is less than 10002 and will be �� k.
//The given num does not contain any leading zero.
//Example 1 :
//
//	Input : num = "1432219", k = 3
//	Output : "1219"
//	Explanation : Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
//	Example 2 :
//
//	Input : num = "10200", k = 1
//	Output : "200"
//	Explanation : Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

//����ջ�����������ַ���ջ��
//��ջ�е����ȵ�ǰԪ�ش��ֵ
//

class Solution_402 {
public:
	string removeKdigits(string num, int k) {
		if (k == num.size())
			return "0";
		string s;
		for (int i = 0; i<num.size(); i++) {
			while (k>0 && !s.empty() && num[i]<s.back()) {
				s.pop_back();
				k--;
			}
			s.push_back(num[i]);
		}
		//һֱ����ջ��û�г�ջ�������������ɾ����
		while (k-- != 0)
			s.pop_back();
		while (!s.empty() && s[0] == '0')
			s.erase(s.begin());
		return s.empty() ? "0" : s;

	}
};