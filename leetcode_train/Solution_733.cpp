#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<iterator>
using namespace std;


//An image is represented by a 2 - D array of integers, each integer representing the pixel value of the image(from 0 to 65535).
//
//Given a coordinate(sr, sc) representing the starting pixel(row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.
//
//To perform a "flood fill", consider the starting pixel, plus any pixels connected 4 - directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4 - directionally to those pixels(also with the same color as the starting pixel), and so on.Replace the color of all of the aforementioned pixels with the newColor.
//
//At the end, return the modified image.
//
//Example 1:
//Input:
//image = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]
//sr = 1, sc = 1, newColor = 2
//Output : [[2, 2, 2], [2, 2, 0], [2, 0, 1]]
//	Explanation :
//	From the center of the image(with position(sr, sc) = (1, 1)), all pixels connected
//	by a path of the same color as the starting pixel are colored with the new color.
//	Note the bottom corner is not colored 2, because it is not 4 - directionally connected
//	to the starting pixel.



class Solution_733 {
	vector<int>xx{ 0,0,1,-1 };
	vector<int>yy{ 1,-1,0,0 };
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		int m = image.size();
		int n = image[0].size();
		if (image[sr][sc] == newColor)
			return image;
		dfs(image, m, n, sr, sc, newColor, image[sr][sc]);
		image[sr][sc] = newColor;
		return image;
	}
	void dfs(vector<vector<int>>& image, int m, int n, int x, int y, int newColor, int init_color) {
		for (int i = 0; i<4; i++) {
			int new_x = x + xx[i];
			int new_y = y + yy[i];
			if (new_x<0 || new_x >= m || new_y<0 || new_y >= n || image[new_x][new_y] != init_color)
				continue;
			image[new_x][new_y] = newColor;
			dfs(image, m, n, new_x, new_y, newColor, init_color);
		}
	}
};