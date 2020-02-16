#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
#include<map>
using namespace std;

//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
//Return 0 if the array contains less than 2 elements.
//
//Example 1:
//
//Input: [3, 6, 9, 1]
//	Output : 3
//	Explanation : The sorted form of the array is[1, 3, 6, 9], either
//				  (3, 6) or (6, 9) has the maximum difference 3.

//低位优先记述排序

class Solution_164 {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.empty() || nums.size() < 2)
			return 0;

		int maxVal = *max_element(nums.begin(), nums.end());

		int exp = 1;
		int radix = 10;

		vector<int> aux(nums.size());


		while (maxVal / exp > 0) {
			vector<int> count(radix, 0);

			for (int i = 0; i < nums.size(); i++)
				count[(nums[i] / exp) % 10]++;

			for (int i = 1; i < count.size(); i++)
				count[i] += count[i - 1];

			for (int i = nums.size() - 1; i >= 0; i--)
				aux[--count[(nums[i] / exp) % 10]] = nums[i];

			for (int i = 0; i < nums.size(); i++)
				nums[i] = aux[i];

			exp *= 10;
		}

		int maxGap = 0;

		for (int i = 0; i < nums.size() - 1; i++)
			maxGap = max(nums[i + 1] - nums[i], maxGap);

		return maxGap;

	}
};