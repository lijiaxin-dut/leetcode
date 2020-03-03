#include<vector>
#include<random>
#include <iomanip>
#include<algorithm>
using namespace std;

//Given the radius and x - y positions of the center of a circle, write a function randPoint which generates a uniform random point in the circle.
//
//Note:
//
//input and output values are in floating - point.
//radius and x - y position of the center of the circle is passed into the class constructor.
//a point on the circumference of the circle is considered to be in the circle.
//randPoint returns a size 2 array containing x - position and y - position of the random point, in that order.



//随机生成圆圈内部的点
//按照长度去生成
//假设中心为原点,x范围是[-r,r],y也是
//随机生成x,y在圆圈内部
//加上圆心的偏移量即可

class Solution
{
	double r;
	double x;
	double y;
	std::default_random_engine gen;
	std::uniform_real_distribution<double> dist;
public:

	Solution(double radius, double x_center, double y_center)
	{
		r = radius;
		x = x_center;
		y = y_center;
		dist = std::uniform_real_distribution<double>(-r, r);
	}

	vector<double> randPoint() {
		while (true) {
			const double x1 = dist(gen);
			const double y1 = dist(gen);
			const double rp2 = std::pow(r, 2.0);
			if (std::pow(x1, 2.0) + std::pow(y1, 2.0) <= rp2)
				return{ x + x1, y + y1 };
		}
		return std::vector<double>();
	}

};