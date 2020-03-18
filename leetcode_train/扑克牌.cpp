#include<vector>
#include<iostream>
#include <iterator>
#include <algorithm>
#include <random>
#include<unordered_map>
using namespace std;

//题目: 一副从1到n的牌，每次从牌堆顶取一张放桌子上，再取一张放牌堆底，
//直到手中没牌，//最后桌子上的牌是从1到n有序，设计程序，输入n，
//输出牌堆的顺序数组


//首先给定1-n的数组，根据要求，生成结果，记作mark
//假设桌面数组为already_know
//根据mark与already_know之间的映射关系，生成原数组

//rs[mark[i]-1]=already_know[i]


vector<int> resort(int n, vector<int>nums) {
	vector<int>rs;
	int cur_index = 0;
	while (rs.size() < n) {
		if (cur_index < nums.size())
			rs.push_back(nums[cur_index++]);
		if (cur_index < nums.size())
			nums.push_back(nums[cur_index++]);
	}
	return rs;
}
void test_____() {
	std::random_device rd;
	std::mt19937 g(rd());
	int n = 100;
	vector<int>nums;
	for (int i = 0; i < n; i++)
		nums.push_back(i + 1);
	//得到标记位，即1,...,n的结果
	vector<int>mark = resort(n, nums);
	//给出要查询的数组
	vector<int>alreaty_know = nums;
	std::shuffle(alreaty_know.begin(), alreaty_know.end(), g);
	unordered_map<int, int>hash;
	//记录映射关系
	for (int i = 0; i < n; i++) {
		hash[mark[i]] = alreaty_know[i];
	}
	vector<int>rs(n, 0);
	for (int i = 0; i < n; i++) {
		//rs[mark[i] - 1] = alreaty_know[i];
		rs[i] = hash[nums[i]];
	}
	if (alreaty_know != resort(n, rs))
		cout << "error" << endl;

}