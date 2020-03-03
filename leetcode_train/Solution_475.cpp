#include<vector>
#include<string>
#include<unordered_set>
#include<iostream>
#include<algorithm>
using namespace std;


//Winter is coming!Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.
//
//Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.
//
//So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.


//����ÿ�����ӣ��ҵ���������ļ������������������ֵ�����ֵ����

class Solution {
public:
	int findRadius_lrhs(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		int n = houses.size();
		vector<int>dis(n, INT_MAX);

		//�ұ�
		for (int i = 0, j = 0; i<houses.size() && j<heaters.size();) {
			if (houses[i] <= heaters[j]) {
				dis[i] = heaters[j] - houses[i];
				i++;
			}
			else {
				j++;
			}
		}
		//���
		for (int i = houses.size() - 1, j = heaters.size() - 1; i >= 0 && j >= 0;) {
			if (houses[i] >= heaters[j]) {
				dis[i] = min(dis[i], houses[i] - heaters[j]);
				i--;
			}
			else {
				j--;
			}
		}
		return *max_element(dis.begin(), dis.end());
	}
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		int n = houses.size();
		vector<int>dis(n, INT_MAX);
		for (int i = 0; i<houses.size(); i++) {
			for (int j = 0; j<heaters.size(); j++) {
				dis[i] = min(dis[i], abs(houses[i] - heaters[j]));
			}
		}
		return *max_element(dis.begin(), dis.end());
	}
};

