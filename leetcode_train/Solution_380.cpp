#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

//Design a data structure that supports all following operations in average O(1) time.
//
//insert(val) : Inserts an item val to the set if not already present.
//remove(val) : Removes an item val from the set if present.
//getRandom : Returns a random element from current set of elements.Each element must have 
//the same probability of being returned.


class RandomizedSet {
public:
	unordered_map<int, int> hash_map;//记录元素在哪个位置
	vector<int>nums;

	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (hash_map.find(val) == hash_map.end())
		{
			nums.push_back(val);
			hash_map[val] = nums.size() - 1;
			return true;
		}
		return false;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (hash_map.count(val) == 0)
			return false;
		int index = hash_map[val];
		//更新数组元素
		nums[index] = nums.back();
		nums.pop_back();
		//更新最后一个元素的新位置
		hash_map[nums[index]] = hash_map[val];
		hash_map.erase(val);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		if (!nums.empty())
			return nums[rand() % nums.size()];
		else
			return -1;
	}
};



//int main() {
//	RandomizedSet* obj = new RandomizedSet();
//	cout << obj->remove(0) << endl;
//	cout << obj->remove(0) << endl;
//	cout << obj->insert(0) << endl;
//	cout << obj->remove(0) << endl;
//	cout << obj->insert(0) << endl;
//}