#include<unordered_set>
#include<vector>

using namespace std;

//Given a non - empty array of numbers, a0, a1, a2, …, an - 1, where 0 ≤ ai < 231.
//
//	Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
//
//	Could you do this in O(n) runtime ?
//
//	Example :
//
//	Input : [3, 10, 5, 25, 2, 8]
//
//	Output : 28
//
//	Explanation : The maximum result is 5 ^ 25 = 28.



//已知   a^b=x  则 a^x=b
//按位确定

//每一次将所有数字的前i位保存到set中

//以最高位为例子，把所有的数字的最高位放到一个HashSet里面，
//然后使用1与set里面的所有数字进行异或，
//如果得出的结果仍然在set里面，那么最终结果的最高位必然为1，否则为0。

//比如  假设第四位为1  1000  set中有1000  0000
//1000^1000==0000  则假设正确，第四位为1
//a^b=x  则 a^x=b


class Solution_421 {
public:
	int findMaximumXOR(vector<int>& nums) {
		int rs = 0;
		int mark = 0;
		for (int i = 31; i >= 0; i--) {
			mark = mark | (1 << i);
			unordered_set<int>hash_set;
			for (auto one_num : nums)
				hash_set.insert(one_num&mark);
			int t = rs | (1 << i);
			for (auto pre : hash_set) {
				if (hash_set.count(pre^t)) {
					rs = t;
					break;
				}
			}
		}
		return rs;
	}
};