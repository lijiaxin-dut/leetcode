#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

class Solution {
	int find_digit(int n) {
		int rs = 0;
		long cur_sum_sigit = 0;
		while (cur_sum_sigit<n) {
			cur_sum_sigit = cur_sum_sigit + 9 * pow(10, rs)*(rs + 1);
			rs++;
		}
		return rs;
	}
	int count_digit_number(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 9;
		return 9 * pow(10, n - 1)*n + count_digit_number(n - 1);
	}
public:
	int findNthDigit(long n) {
		//��n������һ��digit����
		int digit = find_digit(n);
		//��digit������n��
		n = n - count_digit_number(digit - 1);
		//��digitλ�ĵڼ�λ����
		int digit_n_th_number = (n - 1) / digit;
		//��һ��digitλ������
		int first_digit = pow(10, digit - 1);
		//Ŀ������
		int rs_digit= first_digit + digit_n_th_number;
		n = (n - 1) % digit;
		//rs_dight�еĵ�nλ
		return to_string(rs_digit)[n] - '0';
	}
};

