#include<iostream>
#include<vector>

using namespace std;

//quick find
class UF {
public:
	//����i�ķ���id
	vector<int>id;
	//��ͨ��������Ŀ
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
		//��id_i����ͨ�����޸�Ϊq������
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
	//��ʾͬһ����������һ��������֣���Ϊ����
	vector<int>id;
	//��ͨ��������Ŀ
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
	//���ϵ��ҵ����ڵ�
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
		//��id_i����ͨ�����޸�Ϊq������
		id[p_id] = q_id;
		count--;
	}
	bool connected(int p, int q) {
		return find(p) == find(q);
	}
};



//weighted quick union
//ÿ�ν�С�����ӵ�����
class UF_2 {
public:
	//��ʾͬһ����������һ��������֣���Ϊ����
	vector<int>id;
	vector<int>sz;
	//��ͨ��������Ŀ
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
	//���ϵ��ҵ����ڵ�
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
		//��id_i����ͨ�����޸�Ϊq������
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
//ÿ�ν�С�����ӵ�����
//
class UF_3 {
public:
	//��ʾͬһ����������һ��������֣���Ϊ����
	vector<int>id;
	vector<int>sz;
	//��ͨ��������Ŀ
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
	//���ϵ��ҵ����ڵ�
	//�ҵ����ڵ�󣬽�·���Ľڵ�ĸ��ڵ㶼����Ϊ�ҵ��ĸ��ڵ�
	int find(int p) {
		//�ҵ���ǰ�ڵ�ĸ��ڵ�
		int root = p;
		while (id[root] != root)
			root = id[root];
		//�޸�·���Ͻڵ�ĸ��ڵ�
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
		//��id_i����ͨ�����޸�Ϊq������
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