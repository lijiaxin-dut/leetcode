#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;
//
//There are N children standing in a line.Each child is assigned a rating value.
//
//You are giving candies to these children subjected to the following requirements :
//
//Each child must have at least one candy.
//Children with a higher rating get more candies than their neighbors.
//What is the minimum candies you must give ?

//贪心，两遍循环
//初始所有人都是1
//从左向右遍历，不断+1
//然后从右向左遍历，取当前值和上一个+1的最大值

class Solution_135 {
public:
	int candy(vector<int>& ratings) {
		int left = 0;
		int n = ratings.size();
		vector<int>each_child(n, 1);
		each_child[0] = 1;
		for (int i = 0; i<n - 1; i++) {
			if (ratings[i]<ratings[i + 1])
				each_child[i + 1] = each_child[i] + 1;
		}
		for (int i = n - 1; i>0; i--) {
			if (ratings[i - 1]>ratings[i])
				each_child[i - 1] = max(each_child[i - 1], each_child[i] + 1);
		}
		int sum = 0;
		for (int i = 0; i<n; i++)
			sum += each_child[i];
		return sum;
	}
};
