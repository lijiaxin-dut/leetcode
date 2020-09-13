#include<vector>

using namespace std;

class ReverseStack {
public:
	//递归到最深处，返回最后一个元素
	int get_and_remove_last_element(vector<int>&stack) {
		int result = stack.back();
		stack.pop_back();
		if (stack.empty())
			return result;
		else {
			int last = get_and_remove_last_element(stack);
			//除了最后一次，要把上面pop的元素在插入进去
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