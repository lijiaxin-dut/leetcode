﻿#include<vector>
#include<unordered_map>

using namespace std;

//给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。
//
//
//
//示例：
//
//输入：A = [4, 5, 0, -2, -3, 1], K = 5
//输出：7
//解释：
//有 7 个子数组满足其元素之和可被 K = 5 整除：
//[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
//

//同余定理
//sum[j] - sum[i])\%K = 0(sum[j]−sum[i])%K=0 ，
//则必有 sum[j]\%K = sum[i]\%Ksum[j]%K=sum[i]%K。



class Solution {
public:
	int subarraysDivByK(vector<int>& A, int k) {
		unordered_map<int, int>m;
		int n = A.size();
		int sum = 0;
		m[0] = 1;
		for (int i = 0; i<n; i++) {
			sum += A[i];
			int index = sum >= 0 ? sum%k : ((sum%k) + k) % k;
			m[index]++;
		}
		int rs = 0;
		for (auto i : m) {
			rs += (i.second*(i.second - 1)) / 2;
		}
		return rs;
	}
};