#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<stack>
#include<sstream>
using namespace std;

//
//Example 1:
//
//Input: "/home/"
//	Output : "/home"
//	Explanation : Note that there is no trailing slash after the last directory name.
//	Example 2 :
//
//	Input : "/../"
//	Output : "/"
//	Explanation : Going one level up from the root directory is a no - op, as the root level is the highest level you can go.
//	Example 3 :
//
//	Input : "/home//foo/"
//	Output : "/home/foo"
//	Explanation : In the canonical path, multiple consecutive slashes are replaced by a single one.
//	Example 4 :
//
//	Input : "/a/./b/../../c/"
//	Output : "/c"
//	Example 5 :
//
//	Input : "/a/../../b/../c//.//"
//	Output : "/c"
//	Example 6 :
//
//	Input : "/a//b////c/d//././/.."
//	Output : "/a/b/c"
//


//sstream
//使用‘/’对字符串进行分割
//遇到‘.’或空字符串就跳过
//遇到‘..’弹出已找到的地址


class Solution_71 {
public:
	string simplifyPath(string path) {
		string temp;
		vector<string>my_stack;
		stringstream ss(path);
		while (getline(ss, temp, '/')) {
			if (temp.empty())
				continue;
			if (temp == ".")
				continue;
			if (temp == ".." && !my_stack.empty())
				my_stack.pop_back();
			else if (temp == ".."&&my_stack.empty()) {
				continue;
			}
			else {
				my_stack.push_back(temp);
			}
		}
		string rs = "/";
		for (int i = 0; i<my_stack.size(); i++)
		{
			rs += my_stack[i] + "/";
		}
		if (rs.size() > 1)
			rs.pop_back();
		return rs;

	}
};

//int main() {
//	Solution_71 s;
//	s.simplifyPath("/a/./b/../../c/");
//}