#include<vector>
#include<set>
#include<unordered_set>
#include<queue>

//
//A gene string can be represented by an 8 - character long string, with choices from "A", "C", "G", "T".
//
//Suppose we need to investigate about a mutation(mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.
//
//For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
//
//Also, there is a given gene "bank", which records all the valid gene mutations.A gene must be in the bank to make it a valid gene string.
//
//Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end".If there is no such a mutation, return -1.

using namespace std;

class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		unordered_set<string>bank_set(bank.begin(), bank.end());
		vector<char>change_gen{ 'A','C','G','T' };
		queue<string>q;
		q.push(start);
		int rs = 0;
		while (!q.empty()) {
			int cur_size = q.size();
			rs++;
			for (int i = 0; i<cur_size; i++) {
				auto cur_gen = q.front();
				q.pop();
				for (int i = 0; i<cur_gen.size(); i++) {
					char old = cur_gen[i];
					for (auto one_changed : change_gen) {
						if (one_changed == old)
							continue;
						cur_gen[i] = one_changed;
						if (bank_set.find(cur_gen) != bank_set.end()) {
							q.push(cur_gen);
							bank_set.erase(cur_gen);
							if (cur_gen == end)
								return rs;
						}
					}
					cur_gen[i] = old;
				}

			}

		}
		return -1;
	}
};