#include<vector>
#include<unordered_map>

using namespace std;
//
//Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points(i, j, k) such that the distance between i and j equals the distance between i and k(the order of the tuple matters).
//
//Find the number of boomerangs.You may assume that n will be at most 500 and coordinates of points are all in the range[-10000, 10000](inclusive).


//对于每个一个顶点，使用hash_map保存所有的距离，并计数
//如果存在相同的距离为n  n*(n-1)就是结果

class Solution {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		int rs = 0;
		for (int i = 0; i<points.size(); i++) {
			unordered_map<int, int>hash_map;
			for (int j = 0; j<points.size(); j++) {
				if (i == j)
					continue;
				int xx = points[i][0] - points[j][0];
				int yy = points[i][1] - points[j][1];
				int l = pow(xx, 2) + pow(yy, 2);
				hash_map[l]++;
			}
			for (auto &one : hash_map) {
				if (one.second >= 2) {
					int num = one.second;
					rs += (num - 1)*num;
				}
			}
		}


		return rs;
	}
};