#include<iostream>
using namespace std;

//二叉搜索树

class tree_node {
public:
	int n;//以该节点为根节点的子树的节点数
	int key;
	tree_node *left;
	tree_node *right;
	tree_node() = default;
	tree_node(int key, tree_node *l, tree_node *r, int n) :key(key), left(l), right(r), n(n) {}
};
class binary_search_tree {
	
public:
	tree_node *root=nullptr;//二叉树的根节点
	//返回树中节点的数目
	int size() {
		return size(root);
	}
	int size(tree_node *x) {
		if (x == nullptr)
			return 0;
		else
			return x->n;
	}
	//返回key对应的tree_node
	tree_node *get(int key) {
		return get(root, key);
	}
	tree_node *get(tree_node *x, int k) {
		if (x == nullptr)
			return nullptr;
		if (x->key > k) {
			return get(x->left, k);
		}
		else if (x->key < k) {
			return get(x->right, k);
		}
		else
			return x;
	}
	void put(int key) {
		root = put(root, key);
	}
	tree_node * put(tree_node *x, int key) {
		if (x == nullptr)
			return new tree_node(key, nullptr, nullptr, 1);
		if (x->key < key)
			x->right = put(x->right, key);
		else if (x->key > key) 
			x->left = put(x->left, key);
		else
			x->key = key;
		x->n = size(x->left) + size(x->right) + 1;//按照递归路线，逐渐上升修改节点的数目
		return x;
	}
	tree_node *min() {
		return min(root);
	}
	tree_node*min(tree_node *x) {
		if (x->left == nullptr)
			return x;
		else
			return min(x->left);	
	}

	void print() {
		print(root);
	}
	void print(tree_node *x) {
		if (x == nullptr)return;
		print(x->left);
		cout << x->key << endl;
		print(x->right);
	}

};

//int main() {
//	binary_search_tree bst;
//	bst.put(5);
//	bst.put(1);
//	bst.put(10);
//	bst.put(0);
//	bst.put(4);
//	bst.put(12);
//	cout <<"size\t" <<bst.size() << endl;
//	cout << "min value\t"<<bst.min()->key << endl;
//	cout << "value 5\t" << bst.get(5)->key << endl;
//	bst.print();
//}