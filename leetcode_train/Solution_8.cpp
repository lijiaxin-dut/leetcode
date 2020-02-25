#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//ʵ���ַ���ת����
//���Կ�ʼ�Ŀո�
//���Կո�󣬵�һ���ַ�����+ - �������֣���¼�����򲻺Ϸ�
//��֪�ҵ���һ���������ֵ�λ�ã�ֹͣ
//�������ֵĹ����У��ж��Ƿ����
//�����͸����ж�����ķ�ʽ��ͬ����Χ��ͬ

class Solution_8 {
public:
	int myAtoi(string str) {
		int n = str.size();
		
		bool is_negative = false;
		int cur_index = 0;
		for (; cur_index<n; cur_index++) {
			if (str[cur_index] == ' ')
				continue;
			else if (str[cur_index] == '+') {
				cur_index++;
				break;
			}
			else if (str[cur_index] == '-') {
				cur_index++;
				is_negative = true;
				break;
			}
			else if (str[cur_index] >= '0'&&str[cur_index] <= '9') {
				break;
			}
			else
				return 0;
		}
		int rs = 0;
		for (; cur_index<n; cur_index++) {
			if (str[cur_index] >= '0'&&str[cur_index] <= '9') {
				if (rs > INT_MAX / 10 || (rs == INT_MAX / 10 && str[cur_index] > '7')) {
					if (is_negative == false)
						return INT_MAX;
					if (is_negative == true)
						return INT_MIN;
				}
				rs = 10 * rs + (str[cur_index] - '0');
				
			}
			else
				break;
		}
		if (is_negative == true)
			rs = -rs;
		return rs;

	}
};


//int main() {
//	Solution_8 s;
//	s.myAtoi("-42");
//}