#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
//
//假设Andy和Doris想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。
//
//你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。
//
//示例 1:
//
//输入:
//["Shogun", "Tapioca Express", "Burger King", "KFC"]
//["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
//输出 : ["Shogun"]
//	解释 : 他们唯一共同喜爱的餐厅是“Shogun”。
//

class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		vector<string>rs;
		unordered_map<string, int>m1;
		for (int i = 0; i<list1.size(); i++) {
			m1[list1[i]] = i;
		}
		int min_sum = INT_MAX;
		for (int i = 0; i<list2.size(); i++) {
			auto it = m1.find(list2[i]);
			if (it != m1.end()) {
				int new_sum = i + it->second;
				if (new_sum<min_sum) {
					rs.clear();
					rs.push_back(list2[i]);
					min_sum = new_sum;
				}
				else if (new_sum == min_sum) {
					rs.push_back(list2[i]);
				}
			}
		}
		return rs;
	}
};