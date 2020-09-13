#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


//���ӣ�https://www.nowcoder.com/questionTerminal/35fac8d69f314e958a150c141894ef6a
//
//СQ����ĩ��ʱ�������С�����������й�֣�һ�����н����кܶ��¥������n����¥�ų�һ�С�
//СQ�ӵ�һ��һֱ�ߵ������һ����СQ������û�м�����ô���¥����������֪������ÿ��¥��λ�ô��ܿ������ٶ�¥�أ�����ǰ���¥�ĸ߶ȴ��ڵ��ں����¥ʱ�������¥������ס��
//
//�������� :
//�����һ�н�����һ������n������¥�Ķ�������������һ�н�����n������wi(1 <= i <= n)������ÿһ��¥�ĸ߶ȡ�
//1 <= n <= 100000;
//1 <= wi <= 100000;
//
//
//�������:
//���һ�У������ո�ָ��n������vi���ֱ����СQ�ڵ�i��¥ʱ�ܿ�����¥��������
//ʾ��1
//����
//6
//5 3 8 3 2 5
//���
//3 3 5 4 4 4


class Solution {
public:
	void calculate() {
		int n, x[100001];
		cin >> n;
		int ans = 0;
		vector<int> a, b;
		stack<int> st1, st2;
		for (int i = 0; i < n; i++) cin >> x[i];

		for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
			a.push_back(st1.size());
			b.push_back(st2.size());

			while (!st1.empty() && st1.top() <= x[i]) st1.pop();
			while (!st2.empty() && st2.top() <= x[j]) st2.pop();
			st1.push(x[i]);
			st2.push(x[j]);
		}
		reverse(b.begin(), b.end());
		for (int i = 0; i < n; i++) cout << b[i] + a[i] + 1 << " ";
		return ;
	}

};
