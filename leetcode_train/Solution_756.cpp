#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<iterator>
#include<queue>
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;


//We are stacking blocks to form a pyramid.Each block has a color which is a one letter string.
//
//We are allowed to place any color block C on top of two adjacent blocks of colors A and B, if and only if ABC is an allowed triple.
//
//We start with a bottom row of bottom, represented as a single string.We also start with a list of allowed triples allowed.Each allowed triple is represented as a string of length 3.
//
//Return true if we can build the pyramid all the way to the top, otherwise false.




class Solution_756 {
public:
	bool pyramidTransition(string bottom, vector<string>& allowed) {
		if (bottom.size() == 2) {
			for (auto &one_all : allowed) {
				if (one_all[0] == bottom[0] && one_all[1] == bottom[1]) {
					return true;
				}
			}
			return false;
		}
		vector<string>new_bottom{ "" };
		//构造上一层所有可能的情况
		for (int i = 0; i<bottom.size() - 1; i++) {
			string t;
			for (auto &one_all : allowed) {
				if (one_all[0] == bottom[i] && one_all[1] == bottom[i + 1]) {
					t.push_back(one_all[2]);
				}
			}
			vector<string>temp;
			for (auto &one_char : t) {
				for (auto one_pre : new_bottom) {
					temp.push_back(one_pre);
					temp.back().push_back(one_char);
				}
			}
			new_bottom = temp;
		}
		for (auto &pre_bottom : new_bottom) {
			//跳过不可能的解
			if (pre_bottom.size() + 1 != bottom.size())
				continue;
			if (pyramidTransition(pre_bottom, allowed) == true)
				return true;
		}
		return false;
	}
};
