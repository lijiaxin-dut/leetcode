#include<vector>
#include<set>
#include<algorithm>


using namespace std;

//A city's skyline is the outer contour of the silhouette formed by all the buildings 
//in that city when viewed from a distance. Now suppose you are given the locations 
//and height of all the buildings as shown on a cityscape photo (Figure A), 
//write a program to output the skyline formed by these buildings collectively (Figure B).

//�� multiset �з���һ��0��������ĳ��û�к����������ص����ұ߽��ϣ�
//�Ϳ��Խ���յ������ res �С�

//ʹ��multi_set���������󶥵㣬
//�����Ҷ���ʱ������Ӧ���󶥵�ɾ��

//�����ǰ�����߶���ǰһ���߶Ȳ�ͬ���򱣴浱ǰ�ڵ�͵�ǰ�߶�
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
			//��߽�
			if (one_point.second<0) {
				m.insert(-one_point.second);
			}
			//�����ҽڵ�
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