#include<list>
#include<unordered_map>

using namespace std;

//
//Design and implement a data structure for Least Recently Used(LRU) cache.It should support the following operations : get and put.
//
//get(key) - Get the value(will always be positive) of the key if the key exists in the cache, otherwise return -1.
//put(key, value) - Set or insert the value if the key is not already present.When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//
//The cache is initialized with a positive capacity.
//
//Follow up :
//Could you do both operations in O(1) time complexity ?

//使用双向链表和hash_map
//list<pair<int, int>>my_list;     ---->保存数，key  ---  value
//unordered_map<int, list<pair<int, int>>::iterator>my_map    ----->保存key 和这个key在链表中所在的位置
//每次访问时，将访问的节点修改到链表的开头的位置

//list发生移动时，迭代器不会失效


class LRUCache {
	int current_size = 0;
	int capacity = 0;
	list<pair<int, int>>my_list;
	unordered_map<int, list<pair<int, int>>::iterator>my_map;

public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		auto it = my_map.find(key);//返回指向map的迭代器，指向一个pair
		if (it == my_map.end())
			return -1;
		//把it所指的位置调整到链表头部
		my_list.splice(my_list.begin(), my_list, it->second);
		return it->second->second;
	}

	void put(int key, int value) {
		auto it = my_map.find(key);
		//如果已经在list中，需要修改key所读应的value的值
		if (it != my_map.end()) {
			//把it所指的位置调整到链表头部
			my_list.splice(my_list.begin(), my_list, it->second);
			it->second->second = value;
			return;
		}
		//需要删除一个节点
		if (capacity == current_size) {
			current_size--;
			auto remove_key_value = my_list.back();
			my_list.pop_back();
			//根据key的值，在map中删除
			my_map.erase(remove_key_value.first);
		}
		current_size++;
		my_list.emplace_front(key, value);
		my_map[key] = my_list.begin();

	}
};
