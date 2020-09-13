#include<vector>

using namespace std;


//�������ڣ������ұ߽����α��


class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		int max_val = (target + 1) / 2;
		int left = 1;
		int right = 1;
		int sum = 0;
		vector<vector<int>> rs;
		while (left<max_val) {
			if (sum<target) {
				sum += right;
				right++;
			}
			else if (sum>target) {
				sum -= left;
				left++;
			}
			else {
				vector<int>r;
				for (int i = left; i<right; i++) {
					r.push_back(i);
				}
				rs.push_back(std::move(r));
				sum -= left;
				left++;
			}

		}
		return rs;
	}
};