#include<vector>
#include<queue>
#include<set>
using namespace std;

//Median is the middle value in an ordered integer list.If the size of the list is even, there is no middle value.So the median is the mean of the two middle value.
//
//Examples:
//[2, 3, 4], the median is 3
//
//[2, 3], the median is(2 + 3) / 2 = 2.5
//
//Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.You can only see the k numbers in the window.Each time the sliding window moves right by one position.Your job is to output the median array for each window in the original array.
//
//For example,
//Given nums = [1, 3, -1, -3, 5, 3, 6, 7], and k = 3.
//
//Window position                Median
//-------------- - ---- -
//[1  3 - 1] - 3  5  3  6  7       1
//1[3 - 1 - 3] 5  3  6  7 - 1
//1  3[-1 - 3  5] 3  6  7 - 1
//1  3 - 1[-3  5  3] 6  7       3
//1  3 - 1 - 3[5  3  6] 7       5
//1  3 - 1 - 3  5[3  6  7]      6
//Therefore, return the median sliding window as[1, -1, -1, 3, 5, 6].


//1.每次在set中找中间的数，需要遍历
//2.类似于Find Median from Data Stream
//使用两个优先队列，一部分最大值，一部分最小值
//插入与Find Median from Data Stream相同
//删除时，保证两个队列平衡
//使用multiset代替优先队列


//multiset的erase函数的参数不能是reverse_iterator


class Solution {
	void insert(multiset<long>&small, multiset<long>&right, int val) {
		small.insert(val);
		right.insert(*small.rbegin());
		small.erase(small.find(*small.rbegin()));
		if (right.size()>small.size()) {
			small.insert(*right.begin());
			right.erase(right.find(*right.begin()));
		}
	}
	void erase(multiset<long>&small, multiset<long>&right, int val) {
		if (small.count(val)) {
			//在small中删除
			small.erase(small.find(val));
			if (right.size()>small.size()) {
				small.insert(*right.begin());
				right.erase(right.find(*right.begin()));
			}
		}
		else {
			//在right中删除
			right.erase(right.find(val));
			if (small.size() - right.size()>1) {
				right.insert(*small.rbegin());
				small.erase(small.find(*small.rbegin()));
			}
		}

	}
	void insert_rs(multiset<long>&small, multiset<long>&right, int k, vector<double>&rs) {
		if (k % 2 == 1)
			rs.push_back(*small.rbegin());
		else
			rs.push_back((*small.rbegin() + (*right.begin())) / 2.0);
	}
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		multiset<long>small;//最大堆
		multiset<long>right;//最小堆
		vector<double>rs;
		for (int i = 0; i<k; i++) {
			insert(small, right, nums[i]);
		}
		insert_rs(small, right, k, rs);
		int left = 0;
		for (int i = k; i<nums.size(); i++) {
			erase(small, right, nums[left]);
			insert(small, right, nums[i]);
			left++;
			insert_rs(small, right, k, rs);
		}
		return rs;

	}
};