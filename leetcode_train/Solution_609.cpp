#include<vector>
#include<algorithm>
#include<unordered_map>
#include<sstream>

using namespace std;


//给定一个目录信息列表，包括目录路径，以及该目录中的所有包含内容的文件，您需要找到文件系统中的所有重复文件组的路径。一组重复的文件至少包括二个具有完全相同内容的文件。
//
//输入列表中的单个目录信息字符串的格式如下：
//
//"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
//
//这意味着有 n 个文件（f1.txt, f2.txt ... fn.txt 的内容分别是 f1_content, f2_content ... fn_content）在目录 root / d1 / d2 / ... / dm 下。注意：n >= 1 且 m >= 0。如果 m = 0，则表示该目录是根目录。
//
//该输出是重复文件路径组的列表。对于每个组，它包含具有相同内容的文件的所有文件路径。文件路径是具有下列格式的字符串：
//
//"directory_path/file_name.txt"
//
//示例 1：
//
//输入：
//["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
//输出：
//[["root/a/2.txt", "root/c/d/4.txt", "root/4.txt"], ["root/a/1.txt", "root/c/3.txt"]]



class Solution {
	vector<string>split(const string &s, char c) {
		stringstream ss(s);
		vector<string>rs;
		string word;
		while (getline(ss, word, c)) {
			rs.push_back(word);
		}
		return rs;
	}
public:
	vector<vector<string>> findDuplicate(vector<string>& paths) {
		unordered_map<string, vector<string>>rs;
		for (const auto &one_path : paths) {
			vector<string>v1 = split(one_path, ' ');
			for (int i = 1; i<v1.size(); i++) {
				vector<string>v2 = split(v1[i], '(');
				v2[1].pop_back();
				rs[v2[1]].push_back(v1[0] + "/" + v2[0]);
			}
		}
		vector<vector<string>>r;
		for (const auto &i : rs) {
			if (i.second.size()>1)
				r.push_back(std::move(i.second));
		}
		return r;

	}
};