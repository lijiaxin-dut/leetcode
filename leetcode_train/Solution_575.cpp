#include<set>
#include<vector>
#include<unordered_set>

using namespace std;

//����һ��ż�����ȵ����飬���в�ͬ�����ִ����Ų�ͬ������ǹ���ÿһ�����ִ���һ���ǹ�������Ҫ����Щ�ǹ�ƽ���ָ�һ���ܵܺ�һ�����á��������ÿ��Ի�õ�����ǹ�����������
//
//ʾ�� 1:
//
//����: candies = [1, 1, 2, 2, 3, 3]
//	��� : 3
//	���� : һ��������������ǹ���ÿһ�ֶ���������
//	���ŷ��䷽�������û��[1, 2, 3], �ܵ�Ҳ���[1, 2, 3]������ʹ���û���ǹ�����������ࡣ
//
//
class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		unordered_set<int>s1;
		for (auto c : candies) {
			s1.insert(c);
		}
		int n = candies.size() / 2;
		if (s1.size() >= n) {
			return n;
		}
		return s1.size();

	}
};