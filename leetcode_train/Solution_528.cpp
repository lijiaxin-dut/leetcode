#include<vector>
#include<random>
#include<xutility>
#include<algorithm>
using namespace std;

//Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.
//
//Note:
//
//1 <= w.length <= 10000
//1 <= w[i] <= 10 ^ 5
//pickIndex will be called at most 10000 times.


//计算前缀和
//计算所有数字的求和sums
//随机生成[0,sums-1]之间的数字
//在前缀和数组中，使用upper_bound，找到第一个大于该数字的位置


class Solution {
	vector<int>pre_sum;
	int sum = 0;
	mt19937 rng{ random_device{}() };
	uniform_int_distribution<int> uni;
public:
	Solution(vector<int>& w) {
		for (int i = 0; i<w.size(); i++) {
			sum += w[i];
			pre_sum.push_back(sum);
		}
		uni = std::uniform_int_distribution<int>(0, sum - 1);
	}

	int pickIndex() {
		int target = uni(rng);
		auto it = upper_bound(pre_sum.begin(), pre_sum.end(), target);
		return it - pre_sum.begin();
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution* obj = new Solution(w);
* int param_1 = obj->pickIndex();
*/