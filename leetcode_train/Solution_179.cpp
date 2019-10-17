#include<vector>
#include<algorithm>
#include<string>


using namespace std;

//Given a list of non negative integers, arrange them such that they form the largest number.
//
//Example 1:
//
//Input: [10, 2]
//	Output : "210"
//	Example 2 :
//
//	Input : [3, 30, 34, 5, 9]
//	Output : "9534330"
//	Note : The result may be very large, so you need to return a string instead of an integer.

//如果按照最高位排列
//30与3   是303，但存在更大的 330

//自定义排序的规则

// (string a, string b) {return a + b>b + a; }

//按照从小到达，依次拼接即可

//单独处理全0的情况



class Solution_179 {
public:
	string largestNumber(vector<int>& nums) {
		vector<string>nums_s;
		for (auto &one_num : nums) {
			nums_s.push_back(to_string(one_num));
		}
		sort(nums_s.begin(), nums_s.end(), [](string a, string b) {return a + b>b + a; });
		string rs;
		for (auto &one_num : nums_s)
			rs += one_num;
		if (rs[0] == '0')
			return "0";
		return rs;
	}
};