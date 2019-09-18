#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//Suppose you have a long flowerbed in which some of the plots are planted and some are 
//not.However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

//Given a flowerbed(represented as an array containing 0 and 1, where 0 means empty
// and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no - adjacent - flowers rule.

//Example 1:
//Input: flowerbed = [1, 0, 0, 0, 1], n = 1
//	Output : True
//	Example 2 :
//	Input : flowerbed = [1, 0, 0, 0, 1], n = 2
//	Output : False


//扫描一遍数组即可 扫描的过程中直接将可以修改的位置置为1
//贪心


class Solution_605 {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int n_size = flowerbed.size();
		int rs = 0;
		for (int i = 0; i<n_size; i++) {
			if (flowerbed[i] == 0) {
				if (i == 0 && (i == n_size - 1 || flowerbed[i + 1] == 0)) {
					rs++;
					flowerbed[i] = 1;
				}
				else if (i == n_size - 1 && (i == 0 || flowerbed[i - 1] == 0)) {
					rs++;
					flowerbed[i] = 1;
				}
				else if (i!=0&&i!=n_size-1&&flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
					rs++;
					flowerbed[i] = 1;
				}
			}
		}
		return rs >= n;

	}
};


//int main() {
//	Solution_605 s;
//	vector<int>n{ 0,1,0 };
//	s.canPlaceFlowers(n, 1);
//}