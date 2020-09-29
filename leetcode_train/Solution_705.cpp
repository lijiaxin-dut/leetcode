#include<vector>
#include<list>

using namespace std;
//
//��ʹ���κ��ڽ��Ĺ�ϣ������һ����ϣ����
//
//�����˵��������Ӧ�ð������µĹ���
//
//add(value)�����ϣ�����в���һ��ֵ��
//contains(value) �����ع�ϣ�������Ƿ�������ֵ��
//remove(value)��������ֵ�ӹ�ϣ������ɾ���������ϣ������û�����ֵ��ʲôҲ������

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