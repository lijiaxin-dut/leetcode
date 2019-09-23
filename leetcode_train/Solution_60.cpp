#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;


//dfs���ɵ�k��ȫ����   tle


//�ҹ���
//1234
//1243
//1324
//1342
//1423
//1432
//2134
//2143
//2314
//2341
//2413
//2431
//3124
//3142
//3214
//3241
//3412 <-- - k = 17
//3421
//4123
//4132
//4213
//4231
//4312
//4321

//ÿһλ��1, 2, 3, 4�ֱ𶼳�����6�Σ������λ�ϵ�����ȷ���ˣ�
//�ڶ���λÿ�����ֶ�������2�Σ�
//���ڶ���λҲȷ���ˣ�������λ�ϵ����ֶ�ֻ������1�Σ�
//��������λȷ���ˣ���ô���ĸ�λ�ϵ�����Ҳֻ�ܳ���һ�Σ�
//������������k = 17���������ÿλ�������ȷ��������k = 17��ת��Ϊ�����±�Ϊ16��


//���λ��ȡ1, 2, 3, 4�е�һ����ÿ�����ֳ���3�� = 6�Σ�
//��Ϊ�����λȷ���ˣ�������λ�����������У�������3����
//��ô���λ�����־ͻ��ظ�3���Σ�������k = 16�ĵ�һλ���ֵ��±�Ϊ16 / 6 = 2���� "1234" �м�3��ȡ����

//�ڶ�λ��ʱ��1, 2, 4��ȡһ����k = 16�����ʱ�� k' = 16 % (3!) = 4��ע��˼������Ϊ��Ҫȡ�࣬
//�������24������6��һ�����֣���ôk=16���λ�þ����ڵ����飨k/6 = 2���еĵ������k%6 = 4�����֡�

class Solution_60 {
public:
	string getPermutation_1(int n, int k) {
		vector<int>nums;
		vector<bool>marks(n + 1, false);
		for (int i = 1; i <= n; i++)
			nums.push_back(i);
		string rs;
		string partial_rs;
		int current_index = 0;
		help(n, nums, marks, rs, partial_rs, k, 0, current_index);
		return rs;

	}
	void help(int n, vector<int>&nums, vector<bool>marks, string &rs, string &partial_rs, int k, int current_length, int &current_index)
	{
		if (!rs.empty())
			return;
		if (current_length == n) {
			current_index++;
			if (current_index == k) {
				cout << rs << endl;
				rs = partial_rs;
			}
			return;
		}
		for (int i = 0; i<nums.size(); i++) {
			if (marks[nums[i]] == false) {
				marks[nums[i]] = true;
				partial_rs.push_back(nums[i] + '0');
				help(n, nums, marks, rs, partial_rs, k, current_length + 1, current_index);
				partial_rs.pop_back();
				marks[nums[i]] = false;

			}
		}

	}
	string getPermutation(int n, int k) {
		string rs;
		vector<int>fac(n, 1);
		for (int i = 1; i<n; i++) {
			fac[i] = fac[i - 1] * i;
		}
		vector<char>num(n);
		for (int i = 0; i<n; i++) {
			num[i] = (i + 1) + '0';
		}
		k--;
		for (int i = n; i>0; i--) {
			int j = k / fac[i - 1];
			k = k%fac[i - 1];
			rs.push_back(num[j]);
			num.erase(num.begin() + j);
		}
		return rs;
	}
};

//int main() {
//	Solution_60 s;
//	s.getPermutation(3, 3);
//}