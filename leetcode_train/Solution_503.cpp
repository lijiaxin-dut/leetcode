#include<vector>
#include<stack>

using namespace std;

//Given a circular array(the next element of the last element is the first element of the array), print the Next Greater Number for every element.The Next Greater Number of a number x is the first greater number to its traversing - order next in the array, which means you could search circularly to find its next greater number.If it doesn't exist, output -1 for this number.
//
//Example 1:
//Input: [1, 2, 1]
//	Output : [2, -1, 2]
//	Explanation : The first 1's next greater number is 2; 
//	The number 2 can't find next greater number; 
//	The second 1's next greater number needs to search circularly, which is also 2.
//


//��ǰ������һ��ѭ������

//�ѵ�ǰ����������ݣ��ں������һ����ͬ������

//Ȼ��������һ�����ڵ�Ԫ����ͬ

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		nums.insert(nums.end(), nums.begin(), nums.end());
		int n = nums.size();
		vector<int>rs(n, -1);
		stack<int>s;
		for (int i = 0; i<n; i++) {
			while (!s.empty() && nums[i]>nums[s.top()]) {
				rs[s.top()] = nums[i];
				s.pop();
			}
			s.push(i);
		}
		rs.erase(rs.begin() + n / 2, rs.end());
		return rs;
	}
};