#include<vector>
using namespace std;

//In a town, there are N people labelled from 1 to N.There is a rumor that one of these people is secretly the town judge.
//
//If the town judge exists, then:
//
//The town judge trusts nobody.
//Everybody(except for the town judge) trusts the town judge.
//There is exactly one person that satisfies properties 1 and 2.
//You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.
//
//If the town judge exists and can be identified, return the label of the town judge.Otherwise, return -1.

//统计信任和被新人的人数
//找到满足条件的



class Solution_997 {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		vector<int>trust_this_people(N + 1);
		vector<int>this_people_trust(N + 1);
		for (auto &one_trust : trust) {
			trust_this_people[one_trust[1]]++;
			this_people_trust[one_trust[0]]++;
		}
		for (int i = 1; i <= N; i++) {
			if (trust_this_people[i] == N - 1 && this_people_trust[i] == 0)
				return i;
		}
		return -1;
	}
};