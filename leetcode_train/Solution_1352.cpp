#include<vector>
#include<set>

using namespace std;

//Implement the class ProductOfNumbers that supports two methods :

//1. add(int num)
//
//Adds the number num to the back of the current list of numbers.
//2. getProduct(int k)
//
//Returns the product of the last k numbers in the current list.
//You can assume that always the current list has at least k numbers.
//At any time, the product of any contiguous sequence of numbers will fit into a single 32 - bit integer without overflowing.

//遇到0之后就将数字置为初始状态
//为了处理特殊情况，在数组前面插入1

class ProductOfNumbers {
	vector<int>A{ 1 };
public:
	ProductOfNumbers() {

	}

	void add(int num) {
		if (num)
			A.push_back(A[A.size() - 1] * num);
		else
			A = { 1 };
	}

	int getProduct(int k) {
		if (k<A.size())
			return A[A.size() - 1] / A[A.size() - k - 1];
		else
			return 0;

	}
};

/**
* Your ProductOfNumbers object will be instantiated and called as such:
* ProductOfNumbers* obj = new ProductOfNumbers();
* obj->add(num);
* int param_2 = obj->getProduct(k);
*/