#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<memory>
#include<unordered_map>
#include<set>
#include<queue>


//�����ƴ���������Ʊ
//�ҵ����е�Ϊ�����Ĳ�ֵ����
//��β������INT_MIN
//�����������������


using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		prices.push_back(INT_MIN);
		int rs = 0;
		int left = 0;
		for (int i = 1; i<prices.size(); i++) {
			if (prices[i - 1]<prices[i]) {
				continue;
			}
			else {
				if (left != i - 1) {
					rs += prices[i - 1] - prices[left];
				}
				left = i;
			}
		}
		return rs;

	}
};