#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:
//
//B.length >= 3
//There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i - 1] < B[i] > B[i + 1] > ... > B[B.length - 1]
//(Note that B could be any subarray of A, including the entire array A.)


//使用双指针的方法，标记左面开始的位置和右面结束的位置
//注意下标的变化

class Solution {
public:
	int longestMountain(vector<int>& A) {
		if (A.size() <= 2)
			return 0;
		//左面开始的位置
		int left = -1;
		//右面结束的位置
		int right = -1;
		int rs = 0;
		//当前判断的位置
		int i = 0;
		while (i + 1<A.size()) {
			//标记左面是不是有山峰
			bool left_part = false;
			//标记右面是不是有山峰
			bool right_part = false;
			left = i;
			//找到左面结束的位置
			while (i + 1<A.size() && A[i]<A[i + 1]) {
				left_part = true;
				i++;
			}
			//找到右面结束的位置
			while (i + 1<A.size() && A[i]>A[i + 1]) {
				right_part = true;
				i++;
			}
			right = i;
			//如果左右都有山峰
			if (left_part == true && right_part == true)
				rs = max(rs, right - left + 1);
			//如果完全是平的，比如[1,1],i需要自增
			else if (left_part == false && right_part == false)
				i++;
			//如果只有左面，算法结束，如果只有右面，i不变，从跳出while的位置开始判断
			else if (left_part == false || right_part == false)
				continue;
		}
		return rs;
	}
};