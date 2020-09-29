#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
//
//����Andy��Doris�������ʱѡ��һ�Ҳ������������Ƕ���һ����ʾ��ϲ���������б�ÿ���������������ַ�����ʾ��
//
//����Ҫ�������������ٵ��������ҳ����ǹ�ͬϲ���Ĳ����� ����𰸲�ֹһ������������д𰸲��Ҳ�����˳�� ����Լ������Ǵ���һ���𰸡�
//
//ʾ�� 1:
//
//����:
//["Shogun", "Tapioca Express", "Burger King", "KFC"]
//["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
//��� : ["Shogun"]
//	���� : ����Ψһ��ͬϲ���Ĳ����ǡ�Shogun����
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