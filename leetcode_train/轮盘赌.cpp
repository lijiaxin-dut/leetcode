#include<random>
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;


void test() {
	std::random_device rd;  // 将用于获得随机数引擎的种子
	std::mt19937 gen(rd()); // 以 rd() 播种的标准 mersenne_twister_engine
	std::uniform_real_distribution<double>r(0, 1);

	vector<double>f{ 1,1,1,3 };//每个的权重
	double sum = 6;//权重求和
	vector<double>p{ 1 / sum,1 / sum,1 / sum,3 / sum };//权重分布
	vector<double>acc_q{ 1 / sum ,2 / sum ,3 / sum,6 / sum };//累计分布
	map<int, int>c;
	for (int i = 0; i < 10000; i++) {
		double random_number = r(gen);
		for (int j = 0; j < 4; j++) {
			if (acc_q[j] > random_number) {
				c[j]++;
				break;
			}
		}
	}
	for (auto &one_pair : c) {
		cout << one_pair.first << "\t" << one_pair.second << endl;;
	}
}