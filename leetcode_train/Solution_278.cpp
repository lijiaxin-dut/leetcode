


//Suppose you have n versions[1, 2, ..., n] and you 
//want to find out the first bad one, which causes all the following ones to be bad.


//���ַ��ҵ���һ��������������Ŀ
//ע����ֹ����
//lo<hi

//��ȷ����ֹ����ʱ����һ������λ2�����ӣ��ж�һ�¼���

bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int lo = 1;
		int hi = n;
		while (lo<hi) {
			int mid = lo + (hi - lo) / 2;
			bool temp = isBadVersion(mid);
			if (temp == true) {
				hi = mid;
			}
			else if (temp == false) {
				lo = mid + 1;
			}
		}
		return lo;

	}
};