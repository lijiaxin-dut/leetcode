#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std; 

//��int��mark,�����Щ��ĸ����

//mark |= 1 << (one_char - 'a');

class Solution_318 {
public:
	int maxProduct(vector<string>& words) {
		vector<long>hash_map;
		for (auto &one_string : words) {
			long mark = 0;
			for (auto &one_char : one_string) {
				mark |= 1 << (one_char - 'a');
			}
			hash_map.push_back(mark);
		}
		int rs = 0;
		for (int i = 0; i<hash_map.size(); i++) {
			for (int j = i + 1; j<hash_map.size(); j++) {
				if ((hash_map[i] & hash_map[j]) == 0) {
					rs = max(rs, (int)words[i].size()*(int)words[j].size());
				}

			}
		}
		return rs;
	}
};

//int main() {
//	Solution_318 s;
//	vector<string>sss{ "abcw","baz","foo","bar","xtfn","abcdef" };
//	s.maxProduct(sss);
//}