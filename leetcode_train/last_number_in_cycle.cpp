#include<list>
using namespace std;


//0, 1, , n - 1��n�������ų�һ��ԲȦ��������0��ʼ��ÿ�δ����ԲȦ��ɾ����m�����֡�������ԲȦ��ʣ�µ����һ�����֡�
//
//���磬0��1��2��3��4��5���������һ��ԲȦ��������0��ʼÿ��ɾ����3�����֣���ɾ����ǰ4������������2��0��4��1��������ʣ�µ�������3��
//
//
//
//ʾ�� 1��
//
//���� : n = 5, m = 3
//	��� : 3
//	ʾ�� 2��
//
//	���� : n = 10, m = 17
//	��� : 2
//


//1.ʹ������ģ�⻷

class Solution {
public:
	int lastRemaining(int n, int m) {
		list<int>l;
		for (int i = 0; i<n; i++)
			l.push_back(i);
		auto it = l.begin();
		int cur_index = 1;
		while (l.size()>1) {
			if (it == l.end())
				it = l.begin();
			if (cur_index == m) {
				it = l.erase(it);
				cur_index = 1;
			}
			else {
				cur_index++;
				it++;
			}
		}
		return l.front();

	}
};
