#include<vector>

using namespace std;

//Suppose you have N integers from 1 to N.We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position(1 <= i <= N) in this array:
//
//The number at the ith position is divisible by i.
//i is divisible by the number at the ith position.
//
//
//Now given N, how many beautiful arrangements can you construct ?

//dfs»ØËÝ

class Solution {
public:
	int countArrangement(int N) {
		int rs = 0;
		vector<bool>mark(N + 1, false);
		dfs(0, mark, rs, 0, N);
		return rs;
	}
	void dfs(int cur_index, vector<bool>&mark, int &rs, int used_number, int N) {
		if (used_number == N&&cur_index == N) {
			rs++;
			return;
		}
		for (int i = 1; i <= N; i++) {
			if (mark[i] == false && (i % (cur_index + 1) == 0 || (cur_index + 1) % i == 0)) {
				mark[i] = true;
				dfs(cur_index + 1, mark, rs, used_number + 1, N);
				mark[i] = false;
			}
		}
	}
};