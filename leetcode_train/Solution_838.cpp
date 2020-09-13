#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//һ������ N �Ŷ���ŵ���ƣ����ǽ�ÿ�Ŷ���ŵ���ƴ�ֱ������

//�ڿ�ʼʱ������ͬʱ��һЩ����ŵ��������������ơ�
//
//ÿ��һ�룬������ߵĶ���ŵ���ƻ��ƶ���������ڵĶ���ŵ���ơ�
//
//ͬ���أ������ұߵĶ���ŵ����Ҳ���ƶ����������Ҳ�����ڶ���ŵ���ơ�
//
//���ͬʱ�ж���ŵ��������һ�Ŵ�ֱ�����Ķ���ŵ���Ƶ����ߣ���������ƽ�⣬ �ù�����Ȼ���ֲ��䡣

//��������� "A....B"���� A = B����ô�ͱ�� "AAAAAA"��
//��������� "R....L"����ô������� "RRRLLL" ���� "RRR.LLL" �����ĸ�����������
//�����ʼ��ǵ������� i �� j�����ǿ��Լ����� k - i �� j - k ������λ�� k ����̬�� 'L'��'R' ���� '.'��
//��������� "L....R"����ʲô��������������

//�˵���Ӹ�����ĸ�����ڴ����������
//������һ��˵�ʱ��ֻ������˵㣬�Ҷ˵㲻���뵽rs��

//��Ҫע����ӵĳ��ȣ���ҪԽ��


class Solution_838 {
public:
	string pushDominoes(string dominoes) {
		dominoes = "L" + dominoes + "R";
		int last_index = 0;
		char last_letter = 'L';
		string rs;
		for (int i = 1; i<dominoes.size(); i++) {
			//�������е�.
			if (dominoes[i] == '.')
				continue;
			//��ǰλ����L
			if (dominoes[i] == 'L') {
				//֮ǰ��λ����L
				if (last_letter == 'L')
					rs += string(i - last_index, 'L');
				//֮ǰ��λ����R
				else {
					int length = i - last_index + 1;
					rs += string(length / 2, 'R');
					if (length % 2 != 0)
						rs += ".";
					rs += string(length / 2 - 1, 'L');
				}
				last_letter = 'L';
			}
			//��ǰλ��ʱR
			else if (dominoes[i] == 'R') {
				//֮ǰ��λ����
				if (last_letter == 'L') {
					rs += "L";
					rs += string(i - last_index - 1, '.');
				}
				//֮ǰ��λ����R
				else
					rs += string(i - last_index, 'R');
				last_letter = 'R';
			}
			last_index = i;
		}
		rs.erase(rs.begin());
		return rs;
	}
};

//int main() {
//	Solution_838 s;
//	s.pushDominoes(".L.R...LR..L..");
//}