
//实现优先队列
//以最大堆为例

template<class T>
class MaxPQ {
	int *pq;
	//N表示当前元素的个数
	//数据存放在pq[1...N]之间
	int N=0;
public:
	MaxPQ(T maxN) {
		pq = new int[maxN + 1];
	}
	~MaxPQ() {
		delete pq;
	}
	bool is_empty() {
		return N == 0;
	}
	int size() {
		return N;
	}
	void insert(T val) {
		pq[++N] = val;
		swim(N);
	}

	//如果k比跟节点大，逐渐将k上移
	void swim(int k) {
		while (k > 1 && pq[k] > pq[k / 2]) {
			std::swap(pq[k], pq[k / 2]);
			k = k / 2;
		}		
	}

	int delmax() {
		int rs = pq[1];
		pq[1] = pq[N--];
		sink(1);
		return rs;
	}
	void sink(int k) {
		//不断的向下移动，大的与子节点交换，直至没有比当前节点大的子节点
		while (2*k<=N) {
			int j = 2 * k;
			if (j < N&&pq[j] < pq[j + 1])
				j++;
			if (pq[k] < pq[j])
				std:: swap(pq[k], pq[j]);
			else
				break;
			k = j;
			
		}
	}
};
//
//#include<iostream>
//int main() {
//	MaxPQ<int> pq(10);
//	pq.insert(5);
//	pq.insert(6);
//	pq.insert(2);
//	pq.insert(10);
//	pq.insert(1);
//	pq.insert(7);
//	while (!pq.is_empty()) {
//		std::cout << pq.delmax() << "\t";
//	}
//}