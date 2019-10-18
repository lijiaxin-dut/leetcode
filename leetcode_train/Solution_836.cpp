#include<vector>

using namespace std;


//A rectangle is represented as a list[x1, y1, x2, y2], 
//where(x1, y1) are the coordinates of its bottom - left corner, and (x2, y2) 
//are the coordinates of its top - right corner.

//分情况考虑即可，分别考虑x轴和y轴


class Solution_836 {
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		if (rec1[2] <= rec2[0] || rec2[2] <= rec1[0] || rec1[3] <= rec2[1] || rec2[3] <= rec1[1])
			return false;
		return true;
	}
};