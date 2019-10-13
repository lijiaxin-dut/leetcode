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

//ʹ��˫�������hash_map
//list<pair<int, int>>my_list;     ---->��������key  ---  value
//unordered_map<int, list<pair<int, int>>::iterator>my_map    ----->����key �����key�����������ڵ�λ��
//ÿ�η���ʱ�������ʵĽڵ��޸ĵ�����Ŀ�ͷ��λ��

//list�����ƶ�ʱ������������ʧЧ


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
		auto it = my_map.find(key);//����ָ��map�ĵ�������ָ��һ��pair
		if (it == my_map.end())
			return -1;
		//��it��ָ��λ�õ���������ͷ��
		my_list.splice(my_list.begin(), my_list, it->second);
		return it->second->second;
	}

	void put(int key, int value) {
		auto it = my_map.find(key);
		//����Ѿ���list�У���Ҫ�޸�key����Ӧ��value��ֵ
		if (it != my_map.end()) {
			//��it��ָ��λ�õ���������ͷ��
			my_list.splice(my_list.begin(), my_list, it->second);
			it->second->second = value;
			return;
		}
		//��Ҫɾ��һ���ڵ�
		if (capacity == current_size) {
			current_size--;
			auto remove_key_value = my_list.back();
			my_list.pop_back();
			//����key��ֵ����map��ɾ��
			my_map.erase(remove_key_value.first);
		}
		current_size++;
		my_list.emplace_front(key, value);
		my_map[key] = my_list.begin();

	}
};
