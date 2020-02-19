#include<map>
#include<random>
#include<vector>
#include<set>
#include<unordered_map>
#include<unordered_set>
using namespace std;
//
//Design a data structure that supports all following operations in average O(1) time.
//
//Note: Duplicate elements are allowed.
//	insert(val) : Inserts an item val to the collection.
//	remove(val) : Removes an item val from the collection if present.
//	getRandom : Returns a random element from current collection of elements.The probability of each element being returned is linearly related to the number of same value the collection contains.

//hash_map[val]所有的下标
//在remove(val)时
//先在修改后的hash_map  insert，
//然后在remove

class RandomizedCollection {
	unordered_map<int, unordered_set<int>> hash_map;
	vector<int>nums;
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {

	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		nums.push_back(val);
		hash_map[val].insert(nums.size() - 1);
		return hash_map[val].size() == 1;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		auto it = hash_map.find(val);
		if (it == hash_map.end())
			return false;
		int index = *it->second.begin();
		nums[index] = nums.back();
		hash_map[val].erase(index);
		hash_map[nums[index]].insert(index);
		hash_map[nums[index]].erase(nums.size() - 1);
		nums.pop_back();
		if (it->second.empty())
			hash_map.erase(it);
		return true;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		if (nums.empty())
			return 0;
		else
			return nums[rand() % nums.size()];
	}
};
/**
* Your RandomizedCollection object will be instantiated and called as such:
* RandomizedCollection* obj = new RandomizedCollection();
* bool param_1 = obj->insert(val);
* bool param_2 = obj->remove(val);
* int param_3 = obj->getRandom();
*/
