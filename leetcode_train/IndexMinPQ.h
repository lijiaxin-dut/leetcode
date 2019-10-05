#pragma once
template<class Key>

//���ϵ��޸�pq��qp

//pqΪ�����ļ��ϣ�����key�Ĵ�С����
//pq[1]Ϊ��Сֵ��Ӧ������
//qp����������pq�е�λ��

//keys������������������Ӧ��value
//keys[k]=value;
//����k��Ӧ��ֵΪvalue

class IndexMinPQ {
public:
	int N;
	int *pq;//Ҫ���涫��������
	int *qp;//����������pq�еĵ�λ��
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
		pq[N] = k;//�����µ�����
		qp[k] = N;//��ǰ����k��pq�е�λ��ΪN
		keys[k] = key;//����k��Ӧ��value
		swim(N);//��λ��N�����������ں��ʵ�λ����
	}

	Key minKey() {
		return keys[pq[1]];
	}

	//������СԪ�ص�����
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
	//λ��i����������λ��j����������Ӧ��value�Ĺ�ϵ
	bool greater(int i, int j) {
		return keys[pq[i]]>keys[pq[j]];
	}
	//����i\j������
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