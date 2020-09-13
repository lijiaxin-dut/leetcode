#include<vector>

using namespace std;

class ReverseStack {
public:
	//�ݹ鵽������������һ��Ԫ��
	int get_and_remove_last_element(vector<int>&stack) {
		int result = stack.back();
		stack.pop_back();
		if (stack.empty())
			return result;
		else {
			int last = get_and_remove_last_element(stack);
			//�������һ�Σ�Ҫ������pop��Ԫ���ڲ����ȥ
			stack.push_back(result);
			return last;
		}
	}
	vector<int> reverseStackRecursively(vector<int> &stack, int top) {
		if (stack.empty())
			return stack;
		int i = get_and_remove_last_element(stack);
		reverseStackRecursively(stack,top);
		stack.push_back(i);
		return stack;
	}
	
};

//int main() {
//	
//	ReverseStack s;
//	vector<int>nums{ 289,435,175,336,432,455,4 };
//	s.reverseStackRecursively(nums, 1);
//}