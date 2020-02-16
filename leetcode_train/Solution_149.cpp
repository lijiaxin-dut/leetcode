#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
#include<map>
using namespace std;




//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
//
//Example 1:
//
//Input: [[1, 1], [2, 2], [3, 3]]
//	Output : 3
//	Explanation :
//	^
//	|
//	| o
//	| o
//	| o
//	+ ------------->
//	0  1  2  3  4
//	Example 2:
//
//   Input: [[1, 1], [3, 2], [5, 3], [4, 1], [2, 3], [1, 4]]
//	   Output : 4
//	   Explanation :
//	   ^
//	   |
//	   | o
//	   | o        o
//	   | o
//	   | o        o
//	   + ------------------->
//	   0  1  2  3  4  5  6


//������ͬ�ĵ�
//������ʱ�����ȿ��ܷ�����ʧ
//����ѳ����ͱ�������������������������������Ҫ���������ֱ�������ǵ����Լ����
//��������8��4��4��2��2��1������������ͬ�����Ͷ���浽һ��ӳ������

class Solution_149{
public:
	int maxPoints(vector<vector<int>>& points) {
		int res = 0;
		for (int i = 0; i < points.size(); ++i) {
			map<pair<int, int>, int> m;
			int duplicate = 1;
			for (int j = i + 1; j < points.size(); ++j) {
				if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
					++duplicate; 
					continue;
				}
				int dx = points[j][0] - points[i][0];
				int dy = points[j][1] - points[i][1];
				int d = gcd(dx, dy);
				++m[{dx / d, dy / d}];
			}
			res = max(res, duplicate);
			for (auto it = m.begin(); it != m.end(); ++it) {
				res = max(res, it->second + duplicate);
			}
		}
		return res;
	}
	int gcd(int a, int b) {
		while (b) {
			a = a % b;
			swap(a, b);
		}
		return a;
	}
};

