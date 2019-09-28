#include<iostream>
#include<vector>

using namespace std;

//quick find
class UF {
public:
	//索引i的分量id
	vector<int>id;
	//联通分量的数目
	int count;
	UF(int N) {
		id.resize(N);
		count = N;
		for (int i = 0; i < N; i++) {
			id[i] = i;
		}
	}
	int get_count() {
		return count;
	}
	int find(int p) {
		return id[p];
	}
	void union_pq(int p, int q) {
		int p_id = find(p);
		int q_id = find(q);
		if (p_id == q_id)
			return;
		//将id_i的联通分量修改为q的名称
		for (int i = 0; i < id.size(); i++)
			if (id[i] == p_id)
				id[i] = q_id;
		count--;
	}
	bool connected(int p, int q) {
		return find(p) == find(q);
	}
};


//quick union
class UF_1 {
public:
	//表示同一个分量中另一个点的名字，称为链接
	vector<int>id;
	//联通分量的数目
	int count;
	UF_1(int N) {
		id.resize(N);
		count = N;
		for (int i = 0; i < N; i++) {
			id[i] = i;
		}
	}
	int get_count() {
		return count;
	}
	//不断的找到根节点
	int find(int p) {
		while (id[p] != p)
			p = id[p];
		return p;
	}
	void union_pq(int p, int q) {
		int p_id = find(p);
		int q_id = find(q);
		if (p_id == q_id)
			return;
		//将id_i的联通分量修改为q的名称
		id[p_id] = q_id;
		count--;
	}
	bool connected(int p, int q) {
		return find(p) == find(q);
	}
};



//weighted quick union
//每次将小树链接到大树
class UF_2 {
public:
	//表示同一个分量中另一个点的名字，称为链接
	vector<int>id;
	vector<int>sz;
	//联通分量的数目
	int count;
	UF_2(int N) {
		id.resize(N);
		sz.resize(N);
		count = N;
		for (int i = 0; i < N; i++) {
			id[i] = i;
			sz[i] = 1;
		}
	}
	int get_count() {
		return count;
	}
	//不断的找到根节点
	int find(int p) {
		while (id[p] != p)
			p = id[p];
		return p;
	}
	void union_pq(int p, int q) {
		int p_id = find(p);
		int q_id = find(q);
		if (p_id == q_id)
			return;
		//将id_i的联通分量修改为q的名称
		if (sz[p_id] < sz[q_id]) {
			id[p_id] = q_id;
			sz[p_id] += sz[q_id];
		}
		else {
			id[q_id] = p_id;
			sz[q_id] += sz[p_id];
		}		
		count--;
	}
	bool connected(int p, int q) {
		return find(p) == find(q);
	}
};

//path compress weighted quick union
//每次将小树链接到大树
//
class UF_3 {
public:
	//表示同一个分量中另一个点的名字，称为链接
	vector<int>id;
	vector<int>sz;
	//联通分量的数目
	int count;
	UF_3(int N) {
		id.resize(N);
		sz.resize(N);
		count = N;
		for (int i = 0; i < N; i++) {
			id[i] = i;
			sz[i] = 1;
		}
	}
	int get_count() {
		return count;
	}
	//不断的找到根节点
	//找到根节点后，将路径的节点的根节点都更新为找到的根节点
	int find(int p) {
		//找到当前节点的根节点
		int root = p;
		while (id[root] != root)
			root = id[root];
		//修改路径上节点的根节点
		while (id[p] != root) {
			int temp = id[p];
			id[p] = root;
			p = temp;
		}
		return root;
	}
	void union_pq(int p, int q) {
		int p_id = find(p);
		int q_id = find(q);
		if (p_id == q_id)
			return;
		//将id_i的联通分量修改为q的名称
		if (sz[p_id] < sz[q_id]) {
			id[p_id] = q_id;
			sz[p_id] += sz[q_id];
		}
		else {
			id[q_id] = p_id;
			sz[q_id] += sz[p_id];
		}
		count--;
	}
	bool connected(int p, int q) {
		return find(p) == find(q);
	}
};

//int main() {
//	int n;
//	cin >> n;
//	UF_2 un_f(n);
//	vector<int>start;
//	vector<int>ends;
//	for (int i = 0; i < n; i++) {
//		int a, b;
//		cin >> a >> b;
//		start.push_back(a);
//		ends.push_back(b);
//	}
//	for (int i = 0; i < n; i++) {
//		if (un_f.connected(start[i], ends[i]))
//			continue;
//		un_f.union_pq(start[i], ends[i]);
//	}
//	cout << un_f.get_count() << " components" << endl;
//}