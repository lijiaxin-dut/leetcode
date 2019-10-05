#pragma once
template<class Key>

//不断的修改pq与qp

//pq为索引的集合，按照key的大小排序
//pq[1]为最小值对应的索引
//qp保存索引在pq中的位置

//keys按照索引保存索引对应的value
//keys[k]=value;
//索引k对应的值为value

class IndexMinPQ {
public:
	int N;
	int *pq;//要保存东西的索引
	int *qp;//保存索引在pq中的的位置
	Key *keys;

	IndexMinPQ(int NMAX) {
		N = 0;
		keys = new Key[NMAX + 1];
		pq = new int[NMAX + 1];
		qp = new int[NMAX + 1];        // make this of length NMAX??
		for (int i = 0; i <= NMAX; i++)

		{
			pq[i] = -1;
			qp[i] = -1;
		}
	}
	~IndexMinPQ() {
		delete keys;
		delete pq;
		delete qp;
	}

	bool isEmpty() {
		return N == 0;
	}
	bool contains(int k) {
		return qp[k] != -1;
	}
	int size() {
		return N;
	}
	void insert(int k, Key key) {
		N++;	
		pq[N] = k;//插入新的索引
		qp[k] = N;//当前索引k在pq中的位置为N
		keys[k] = key;//索引k对应的value
		swim(N);//将位置N处的索引放在合适的位置上
	}

	Key minKey() {
		return keys[pq[1]];
	}

	//返回最小元素的索引
	int delMin() {
		int min = pq[1];
		exch(1, N--);
		sink(1);
		qp[min] = -1; 
		pq[N + 1] = -1;
		return min;

	}
	void change(int k, Key key) {
		keys[k] = key;
		swim(qp[k]);
		sink(qp[k]);
	}
	//位置i处的索引和位置j处的索引对应的value的关系
	bool greater(int i, int j) {
		return keys[pq[i]]>keys[pq[j]];
	}
	//交换i\j的索引
	void exch(int i, int j) {
		int swap = pq[i];
		pq[i] = pq[j];
		pq[j] = swap;
		qp[pq[i]] = i;
		qp[pq[j]] = j;
	}
	void swim(int k) {
		while (k > 1 && greater(k / 2, k)) {
			exch(k, k / 2);
			k = k / 2;
		}
	}
	void sink(int k) {
		while (2 * k <= N) {
			int j = 2 * k;
			if (j < N && greater(j, j + 1))
				j++;
			if (!greater(k, j))
				break;
			exch(k, j);
			k = j;
		}
	}
};