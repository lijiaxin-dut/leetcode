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




class Solution {
public:
	bool pyramidTransition(string bottom, vector<string>& allowed) {
		if (bottom.size() == 1)
			return true;
		vector<string>next_level{ "" };
		for (int i = 0; i<bottom.size() - 1; i++) {
			string temp;
			for (auto &one_allowed : allowed) {
				if (bottom[i] == one_allowed[0] && bottom[i + 1] == one_allowed[1]) {
					temp += one_allowed[2];
				}
			}
			vector<string>partial_level;
			for (auto &one_n : next_level) {
				for (auto &one_c : temp)
					partial_level.push_back(one_n + one_c);
			}
			swap(next_level, partial_level);
		}
		for (auto &one_next : next_level) {
			if (pyramidTransition(one_next, allowed) == true)
				return true;
		}
		return false;

	}
};