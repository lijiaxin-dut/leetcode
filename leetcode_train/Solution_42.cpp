#include<algorithm>
#include<vector>
#include<stack>

using namespace std;
//Given n non - negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//
//The above elevation map is represented by array[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1].In this case, 6 units of rain water(blue section) are being trapped.Thanks Marcos for contributing this image!

//1.Brute force
//对于任意一个位置，
//扫描从左面到当前最大值
//扫描从右面到当前最大值
//二者的最小值-当前值就是当前位置可以存放的水



//2.使用两个数组 
//left_max  左边开始到当前最大(包括当前位置)
//right_max 右边开始到当前最大(包括当前位置)
//rs+=min(left_max,right_max)-height


//3.使用栈  ？？？
//栈为空或者元素<=栈顶元素，就入栈
//否则弹出元素作为坑，下一个元素就是左侧的较高值
//


class Solution_42 {
public:
	int trap_force(vector<int>& height) {
		int ans = 0;
		int n = height.size();
		if (n == 0)
			return 0;
		for (int i = 1; i<n - 1; i++) {
			int left_max = 0;
			for (int j = 0; j <= i; j++)
				left_max = max(left_max, height[j]);
			int right_max = 0;
			for (int j = i; j<n; j++)
				right_max = max(right_max, height[j]);
			ans += min(left_max, right_max) - height[i];
		}
		return ans;
	}
	int trap_stack(vector<int>& height) {
		stack<int>st;
		int i = 0;
		int n = height.size();
		int rs = 0;
		while (i<n) {
			if (st.empty() || height[i] <= height[st.top()]) {
				st.push(i++);
			}
			else {
				int t = st.top(); st.pop();
				if (st.empty())
					continue;
				rs += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
			}
		}
		return rs;
	}
	int trap(vector<int>& height) {
		int n = height.size();
		if (n == 0)
			return 0;
		vector<int>left_max(n, 0);
		vector<int>right_max(n, 0);
		left_max[0] = height[0];
		for (int i = 1; i<n; i++)
			left_max[i] = max(left_max[i - 1], height[i]);
		right_max[n - 1] = height[n - 1];
		for (int i = n - 2; i >= 0; i--)
			right_max[i] = max(right_max[i + 1], height[i]);
		int rs = 0;
		for (int i = 1; i<n - 1; i++)
			rs += min(left_max[i], right_max[i]) - height[i];
		return rs;

	}
};

//int main() {
//	Solution_42 s;
//	vector<int>m{ 0,1,0,2,1,0,1,3,2,1,2,1 };
//	s.trap(m);
//
//}