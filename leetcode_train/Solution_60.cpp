#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;


//dfs生成第k个全排列   tle


//找规律
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

//每一位上1, 2, 3, 4分别都出现了6次，当最高位上的数字确定了，
//第二高位每个数字都出现了2次，
//当第二高位也确定了，第三高位上的数字都只出现了1次，
//当第三高位确定了，那么第四高位上的数字也只能出现一次，
//下面我们来看k = 17这种情况的每位数字如何确定，由于k = 17是转化为数组下标为16：


//最高位可取1, 2, 3, 4中的一个，每个数字出现3！ = 6次（
//因为当最高位确定了，后面三位可以任意排列，所以是3！，
//那么最高位的数字就会重复3！次），所以k = 16的第一位数字的下标为16 / 6 = 2，在 "1234" 中即3被取出。

//第二位此时从1, 2, 4中取一个，k = 16，则此时的 k' = 16 % (3!) = 4，注意思考这里为何要取余，
//如果对这24个数以6个一组来分，那么k=16这个位置就是在第三组（k/6 = 2）中的第五个（k%6 = 4）数字。

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