#include<string>
#include<sstream>
#include<algorithm>


using namespace std;

//Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
//
//Example 1:
//Input: "Let's take LeetCode contest"
//	Output : "s'teL ekat edoCteeL tsetnoc"




class Solution {
public:
	string reverseWords(string s) {
		string rs;
		string temp;
		stringstream ss(s);
		while (getline(ss, temp, ' '))
		{
			reverse(temp.begin(), temp.end());
			rs += temp;
			rs += " ";
			temp.clear();
		}
		return rs.substr(0, rs.size() - 1);

	}

};