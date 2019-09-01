#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//The i - th person has weight people[i], and each boat can carry a maximum weight of limit.

//Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit.

//Return the minimum number of boats to carry every given person.  (It is guaranteed each person can be carried by a boat.)

//首先对数组进行排序
//使用双指针
//一个大数一个小数的进行组合

class Solution_881 {
public:
	int numRescueBoats(vector<int>& people, int limit) {
		if (people.size() <= 1)
			return people.size();
		sort(people.begin(), people.end());
		int left = 0;
		int right = people.size() - 1;
		int rs = 0;
		while (left<right) {
			if (people[left] + people[right] <= limit) {
				left++; right--;
				rs++;
			}
			else if (people[left] + people[right]>limit) {
				right--;
				rs++;
			}
		}
		if (left == right)
			rs++;
		return rs;
	}
};