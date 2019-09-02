#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

//Return the intersection of these two interval lists.

//(Formally, a closed interval[a, b](with a <= b) denotes the set of real numbers x with a <= x <= b.

//The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.For example, the intersection of[1, 3] and [2, 4] is[2, 3].)

//两个指针，分别指向A,B，指向正在判断的数组
//判读两个数组是否有交集
//将最大值较小的数组的索引自增

class Solution_986 {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
		int A_index = 0;
		int B_index = 0;
		vector<vector<int>> rs;
		while (A_index<A.size() && B_index<B.size()) {
			int max_left = max(A[A_index][0], B[B_index][0]);
			int min_right = min(A[A_index][1], B[B_index][1]);
			if (max_left <= min_right) {
				rs.emplace_back(vector<int>{ max_left, min_right });
			}
			//A的当前位置右端较大
			if (A[A_index][1]>B[B_index][1])
				B_index++;
			//B的当前位置右端较大
			else
				A_index++;
		}
		return rs;
	}
};
//int main() {
//	vector<vector<int>>A{ {0,2},{5,10},{13,23},{24,25} };
//	vector<vector<int>>B{ { 1,5 },{ 8,12 },{ 15,24 },{ 25,26 } };
//	Solution_986 s;
//	s.intervalIntersection(A, B);
//}