#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;


//Given a string s that consists of only uppercase English letters, 
//you can perform at most k operations on that string.

//In one operation, you can choose any character of the string and change 
//it to any other uppercase English character.

//Find the length of the longest sub - string containing all repeating 
//letters you can get after performing the above operations.


//����ָ�룬ʹ��map����ָ���м�Ԫ��ÿ��Ԫ�س��ֵĴ���
//���ִ���+k<=frist-second���͵õ�һ���Ϸ��Ľ�


//�������ڲ���Ҫ����
//����k=2;
//��ǰ��ظ���ĸ�Ĵ���Ϊ3�����ڳ���Ϊ5
//��ǰ���Ϊ5
//�����õ�Ϊ6�Ľṹ
//�����ظ�����ĸҪΪ4�Σ�4+2���6

//���Ե�������������ƽ��ʱ������Ҫ���¼�  ��ǰ��ظ���ĸ�ĸ���

class Solution_424 {
public:
	int characterReplacement(string s, int k) {
		if (s.size() <= 1)
			return s.size();
		unordered_map<char, int> mark;
		int current_length = 0;
		int current_start = 0;
		int rs = 0;
		for (int i = 0; i<s.size(); i++) {
			mark[s[i]]++;
			//��ǰ����������ַ���
			current_length = max(current_length, mark[s[i]]);
			//��ǰ����ָ��Ĳ�ֵ<=��ǰ��������+k,��˵������ָ��֮����k�β������Ա�Ϊ��ͬ��������ĸ
			if (i - current_start + 1 <= current_length + k) {
				rs = max(rs, i - current_start + 1);
				continue;
			}
			else {
				//��ָ�����ұ��ƶ���������ָ�뵱ǰָ����ĸ���ֵĴ���
				mark[s[current_start]]--;
				current_start++;
			}
		}
		return rs;
	}
};

//int main() {
//	Solution_424 s;
//	s.characterReplacement("ABAB", 2);
//
//}