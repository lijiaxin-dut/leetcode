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
	bool is_prime(int num) {
		if (num <= 1)
			return false;
		for (int i = 2; i*i <= num; i++) {
			if (num%i == 0)
				return false;
		}
		return true;

	}
public:
	int countPrimes_1(int n) {
		int count = 0;
		for (int i = 1; i<n; i++)
		{
			if (is_prime(i))
				count++;
		}
		return count;
	}

	int countPrimes_2(int n) {
		vector<bool>mark(n + 1, true);
		for (int i = 2; i*i<n; i++) {
			if (mark[i] == false)
				continue;
			//2*i�Ѿ���ɸѡ��
			for (int j = i*i; j<n; j += i) {
				mark[j] = false;
			}
		}
		int rs = 0;
		for (int i = 2; i<n; i++)
			if (mark[i] == true)
				rs++;
		return rs;

	}


};