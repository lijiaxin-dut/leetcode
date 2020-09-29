#include<vector>
#include<list>

using namespace std;
//
//不使用任何内建的哈希表库设计一个哈希集合
//
//具体地说，你的设计应该包含以下的功能
//
//add(value)：向哈希集合中插入一个值。
//contains(value) ：返回哈希集合中是否存在这个值。
//remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。

class MyHashSet {
	vector<list<int>>arr;
public:
	int length = 2001;
	/** Initialize your data structure here. */
	MyHashSet() {
		arr.resize(length);
	}

	void add(int key) {
		int index = key%length;
		arr[index].push_back(key);
	}

	void remove(int key) {
		int index = key%length;
		arr[index].remove(key);
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		int index = key%length;
		for (auto i : arr[index]) {
			if (i == key)
				return true;
		}
		return false;
	}
};

/**
* Your MyHashSet object will be instantiated and called as such:
* MyHashSet* obj = new MyHashSet();
* obj->add(key);
* obj->remove(key);
* bool param_3 = obj->contains(key);
*/