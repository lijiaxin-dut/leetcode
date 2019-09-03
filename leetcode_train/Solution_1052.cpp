#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//On some minutes, the bookstore owner is grumpy.  If the bookstore owner is grumpy on the i-th minute, 
//grumpy[i] = 1,otherwise grumpy[i] = 0.  When the bookstore owner is grumpy, the customers of that 
//minute are not satisfied, otherwise they are satisfied.

//The bookstore owner knows a secret technique to keep themselves not grumpy for X minutes straight, 
//but can only use it once.

//X���ӱ���ʱ�����ģ��ڿ��ΪX�Ĵ������ҵ����Ի�Ծ���Ĺ˿͵Ĵ���
//�������ǿ�ʼ�Ϳ��Է���Ĺ˿���Ŀ
//Ȼ���ʼ��һ������ΪX�Ĵ���
//���Ͻ����ں���

class Solution_1052 {
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
		int rs = 0;
		//�������в���grumpy�ķ���
		for (int i = 0; i < grumpy.size(); i++) {
			if (grumpy[i] == 0)
				rs += customers[i];
		}
		int g_size = 0;
		int g_customer_number = 0;
		for (int i = 0; i < X; i++) {
			if (grumpy[i] == 1) {
				g_customer_number += customers[i];
			}
		}
		int left = 0;
		int right = left + X;
		int best_rs = rs + g_customer_number;
		while (right < grumpy.size()) {
			if (grumpy[right] == 1)
				g_customer_number += customers[right];
			if (grumpy[left] == 1)
				g_customer_number -= customers[left];
			best_rs = max(best_rs, rs + g_customer_number);
			left++;
			right++;
		}
		return best_rs;
	}
};

//int main() {
//	Solution_1052 s;
//	vector<int> customers{4,10,10 };
//	vector<int> grumpy{ 1,1,0 };
//	s.maxSatisfied(customers, grumpy, 2);
//
//}