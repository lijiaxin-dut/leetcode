#include<unordered_map>
#include<list>

using namespace std;

//设计并实现最不经常使用（LFU）缓存的数据结构。它应该支持以下操作：get 和 put。
//
//get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 - 1。
//put(key, value) - 如果键不存在，请设置或插入值。当缓存达到其容量时，它应该在插入新项目之前，使最不经常使用的项目无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，最近最少使用的键将被去除。
//
//Note that the number of times an item is used is the number of calls to the get and put functions for that item since it was inserted.This number is set to zero when the item is removed.



//使用三个unorderd_map
//key->{value,freq}
//freq->set{key}
//iter->映射key在频率中的位置

//在put一对key与value时，调用get确认是否已经在里面

class LFUCache {
	int cap = 0;
	int min_freq;
	unordered_map<int, pair<int, int>>m;
	unordered_map<int, list<int>>freq;
	unordered_map<int, list<int>::iterator>key_iter;
public:
	LFUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		if (m.count(key) == 0)
			return -1;
		freq[m[key].second].erase(key_iter[key]);
		++m[key].second;
		freq[m[key].second].push_back(key);
		key_iter[key] = --freq[m[key].second].end();
		//访问数据导致频率增加
		if (freq[min_freq].empty())
			min_freq++;
		return m[key].first;


	}

	void put(int key, int value) {
		if (cap <= 0)
			return;
		if (get(key) != -1) {
			m[key].first = value;
			return;
		}
		//需要删除一个
		if (m.size() == cap) {
			m.erase(freq[min_freq].front());
			key_iter.erase(freq[min_freq].front());
			freq[min_freq].pop_front();
		}
		m[key] = { value,1 };
		freq[1].push_back(key);
		key_iter[key] = --freq[1].end();
		min_freq = 1;
	}
};

/**
* Your LFUCache object will be instantiated and called as such:
* LFUCache* obj = new LFUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/