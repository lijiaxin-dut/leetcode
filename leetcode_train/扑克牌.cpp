#include<vector>
#include<iostream>
#include <iterator>
#include <algorithm>
#include <random>
#include<unordered_map>
using namespace std;

//��Ŀ: һ����1��n���ƣ�ÿ�δ��ƶѶ�ȡһ�ŷ������ϣ���ȡһ�ŷ��ƶѵף�
//ֱ������û�ƣ�//��������ϵ����Ǵ�1��n������Ƴ�������n��
//����ƶѵ�˳������


//���ȸ���1-n�����飬����Ҫ�����ɽ��������mark
//������������Ϊalready_know
//����mark��already_know֮���ӳ���ϵ������ԭ����

//rs[mark[i]-1]=already_know[i]


vector<int> resort(int n, vector<int>nums) {
	vector<int>rs;
	int cur_index = 0;
	while (rs.size() < n) {
		if (cur_index < nums.size())
			rs.push_back(nums[cur_index++]);
		if (cur_index < nums.size())
			nums.push_back(nums[cur_index++]);
	}
	return rs;
}
void test_____() {
	std::random_device rd;
	std::mt19937 g(rd());
	int n = 100;
	vector<int>nums;
	for (int i = 0; i < n; i++)
		nums.push_back(i + 1);
	//�õ����λ����1,...,n�Ľ��
	vector<int>mark = resort(n, nums);
	//����Ҫ��ѯ������
	vector<int>alreaty_know = nums;
	std::shuffle(alreaty_know.begin(), alreaty_know.end(), g);
	unordered_map<int, int>hash;
	//��¼ӳ���ϵ
	for (int i = 0; i < n; i++) {
		hash[mark[i]] = alreaty_know[i];
	}
	vector<int>rs(n, 0);
	for (int i = 0; i < n; i++) {
		//rs[mark[i] - 1] = alreaty_know[i];
		rs[i] = hash[nums[i]];
	}
	if (alreaty_know != resort(n, rs))
		cout << "error" << endl;

}