#include<vector>
#include<set>
#include<algorithm>


using namespace std;

//A city's skyline is the outer contour of the silhouette formed by all the buildings 
//in that city when viewed from a distance. Now suppose you are given the locations 
//and height of all the buildings as shown on a cityscape photo (Figure A), 
//write a program to output the skyline formed by these buildings collectively (Figure B).

//在 multiset 中放入一个0，这样在某个没有和其他建筑重叠的右边界上，
//就可以将封闭点存入结果 res 中。

//使用multi_set保存所有左顶点，
//遇到右顶点时，将对应的左顶点删除

//如果当前的最大高度与前一个高度不同，则保存当前节点和当前高度
//https://www.cnblogs.com/grandyang/p/4534586.html
class Solution_218 {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>>h;
		for (auto &one_h : buildings) {
			h.push_back(make_pair(one_h[0], -one_h[2]));
			h.push_back(make_pair(one_h[1], one_h[2]));
		}
		sort(h.begin(), h.end());
		int pre = 0;
		int cur = 0;
		multiset<int>m;
		m.insert(0);
		vector<vector<int>>res;
		for (auto &one_point : h) {
			//左边界
			if (one_point.second<0) {
				m.insert(-one_point.second);
			}
			//遇到右节点
			else {
				m.erase(m.find(one_point.second));
			}
			cur = *m.rbegin();
			if (cur != pre) {
				res.push_back({ one_point.first, cur });
				pre = cur;
			}
		}
		return res;
	}
};
//
//int main() {
//	Solution_218 s;
//	vector<vector<int>>t{ {2,9,10},{ 3,7,15 },{ 5,12,12 },{ 15,20,10 },{ 19,24,8 } };
//	s.getSkyline(t);
//}