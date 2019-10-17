#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

//Given two strings s and t, determine if they are isomorphic.

//Two strings are isomorphic if the characters in s can be replaced to get t.

//All occurrences of a character must be replaced with another character 
//while preserving the order of characters.No two characters may map 
//to the same character but a character may map to itself.


//�޸��ַ��������ϵĽ�s[i]��t[i]�����滻
//��¼ÿ���ַ���һ���滻�����
//�ж���������ַ����Ƿ����

//��Ϊ���������Լ�ӳ������
//s[i]=t[i]����һ���滻
//t[i]=s[i]����һ���滻


class Solution_205 {
	bool help(string s, string t) {
		unordered_map<char, char>hash_map;
		for (int i = 0; i<s.size(); i++) {
			if (hash_map.find(s[i]) == hash_map.end()) {
				hash_map[s[i]] = t[i];
				s[i] = t[i];
			}
			else {
				s[i] = hash_map[s[i]];
			}
		}
		return s == t;
	}
public:
	bool isIsomorphic(string s, string t) {
		return help(s, t) && help(t, s);
	}
};