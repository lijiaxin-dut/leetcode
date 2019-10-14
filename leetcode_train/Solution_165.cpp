#include<vector>
#include<sstream>
#include<string>

using namespace std;


//Compare two version numbers version1 and version2.
//If version1 > version2 return 1; if version1 < version2 return -1; otherwise return 0.
//
//	You may assume that the version strings are non - empty and contain only digits and the.character.
//
//	The.character does not represent a decimal point and is used to separate number sequences.
//
//	For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second - level revision of the second first - level revision.
//
//	You may assume the default revision number for each level of a version number to be 0. For example, version number 3.4 has a revision number of 3 and 4 for its first and second level revision number.Its third and fourth level revision number are both 0.
//


//以‘.’为分隔符对字符串进行分割
//然后忽略最后面的零

//从前到后依次比较即可

class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<int>v1;
		vector<int>v2;
		stringstream ss(version1);
		string temp;
		while (getline(ss, temp, '.')) {
			v1.push_back(stoi(temp.c_str()));
		}
		ss = stringstream(version2);
		while (getline(ss, temp, '.')) {
			v2.push_back(stoi(temp.c_str()));
		}
		while (!v1.empty() && v1.back() == 0)
			v1.pop_back();
		while (!v2.empty() && v2.back() == 0)
			v2.pop_back();
		int i = 0;
		for (; i<v1.size() && i<v2.size(); i++) {
			if (v1[i]<v2[i])
				return -1;
			else if (v1[i]>v2[i])
				return 1;
		}
		if (i<v1.size())
			return 1;
		if (i<v2.size())
			return -1;
		return 0;

	}
};