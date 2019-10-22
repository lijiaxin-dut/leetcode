#include<vector>

using namespace std;

//There are n bulbs that are initially off.You first turn on all the bulbs.
//Then, you turn off every second bulb.On the third round, 
//you toggle every third bulb(turning on if it's off or turning off if it's on).
//For the i - th round, you toggle every i bulb.For the n - th round, 
//you only toggle the last bulb.Find how many bulbs are on after n rounds.
//
//Example:
//
//Input: 3
//	Output : 1
//	Explanation :
//	At first, the three bulbs are[off, off, off].
//	After first round, the three bulbs are[on, on, on].
//	After second round, the three bulbs are[on, off, on].
//	After third round, the three bulbs are[on, off, off].
//
//	So you should return 1, because there is only one bulb is on.

//1.����������ѭ������
//2.�ҹ��ɣ�������ĵ�������ȫƽ������Ӧ������
//���ڵ�n�����ݣ�ֻ�е�������n�����ӵ�֮�󣬲��ܸı���ݵ�״̬����n�ܱ���ǰ����������
//���統nΪ36ʱ������������(1,36), (2,18), (3,12), (4,9), (6,6), 
//���Կ���ǰ�ĸ�������ɶԳ��ֵ�����������ͬ��
//������ǰ������ı��˵���״̬����������ֱ��ȥ�ˣ�
//���ڵ��ݵ�״̬û�з����仯��ֻ������Ǹ�(6,6)��
//�ڴ���6��ʱ��ı���һ��״̬��û�ж�Ӧ������״̬
//�ܽ�����ȥ�ˣ����Ե��ݾ�һֱ�ǵ���״̬�ġ�
//��������ƽ����������ôһ����ȵ������ԣ�������ƽ�����ĵ��ݶ������ǵ�����״̬��



class Solution_319 {
public:
	int bulbSwitch_1(int n) {
		int rs = 0;
		for (int i = 1; i*i <= n; i++) {
			rs++;
		}
		return rs;
	}
	int bulbSwitch(int n) {
		vector<bool>mark(n + 1, false);
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j = j + i) {
				mark[i] = !mark[i];
			}
		}
		int rs = 0;
		for (int i = 1; i <= n; i++) {
			if (mark[i] == true)
				rs++;
		}
		return rs;

	}
};

//int main() {
//	Solution_319 s;
//	s.bulbSwitch(3);
//}