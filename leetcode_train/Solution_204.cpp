#include<iostream>
#include<vector>

using namespace std;

//�ж�һ����num�Ƿ�Ϊ����
//�ж�num�ܷ�[2,sqrt(num)]����
//������������������


//������˹����ɸ��
//��2-sqrt(n)
//����2ȥɸ������2���£���2�ı����޳�����
//������һ��������Ҳ����3ɸ����3���£���3�ı����޳�����
//����ȥ����һ������5ɸ����5���£���5�ı����޳����������ظ���ȥ.


class Solution_204 {
	
public:
	int countPrimes(int n) {
		int res = 0;
		vector<bool> prime(n, true);
		for (int i = 2; i < n; ++i) {
			if (!prime[i])
				continue;
			++res;
			//ɸ����ǰ�����ı���
			for (int j = 2; i * j < n; ++j) {
				prime[i * j] = false;
			}
		}
		return res;
	}


};