#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		vector<int>rs;
		auto right = lower_bound(arr.begin(), arr.end(), x);
		auto left = right - 1;
		while (k>0) {
			k--;
			if (left + 1 != arr.begin() && right != arr.end()) {
				int v1 = abs(*left - x);
				int v2 = abs(*right - x);
				if (v1 <= v2) {
					left--;
				}
				else {
					right++;
				}
			}
			else if (left + 1 == arr.begin()) {
				right++;
			}
			else {
				left--;
			}
		}
		for (auto it = left + 1; it != right; it++) {
			rs.push_back(*it);
		}
		return rs;
	}
};

