#include<algorithm>

using namespace std;

//Find the total area covered by two rectilinear rectangles in a 2D plane.
//
//Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.



//判断两个矩形是否相交
//不相交直接返回求和
//若相交，减去交集

//注意越界

class Solution_223 {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		long sum_A = (C - A)*(D - B);
		long sum_B = (G - E)*(H - F);
		if (C <= E || G <= A || D <= F || H <= B)
			return sum_A + sum_B;
		int xx_left = max(A, E);
		int xx_right = min(C, G);
		int yy_low = max(B, F);
		int yy_high = min(D, H);
		return sum_A + sum_B - (xx_right - xx_left)*(yy_high - yy_low);
	}
};