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
//�ҵ����н�����ֵ�λ�ã���¼cur_min
//��β������0
//�����������������


using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1)
			return 0;
		int n = prices.size();
		prices.push_back(0);
		int cur_min = prices[0];
		int rs = 0;
		for (int i = 0; i<n; i++) {
			if (prices[i] >= prices[i + 1]) {
				rs += prices[i] - cur_min;
				cur_min = prices[i + 1];
			}
		}
		return rs;
	}
};