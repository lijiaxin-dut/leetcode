#include<vector>
#include<algorithm>
#include<stack>

using namespace std;
//
//Given n non - negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

//�ҵ�ÿһ���ݼ���λ�ã�Ȼ�����ӿ�ʼλ�õ���λ�õ����


//ʹ�õ���ջ
//�����ڽ���ʱ���Ͳ��ϵĴ�ջ�е�������
//��Ϊ�ǵ���ջ���Ѿ����������ݣ�����ǰ���������ݣ�һ���ܹ��ɳ�����

//1��5��6��2
//��ǰԪ����2
//�ȵ���6������� 6*��3-1-1��=6
//�ڵ���5������� 5*��3-1-0��=10



class Solution_84 {
public:

	//https ://www.geeksforgeeks.org/largest-rectangle-under-histogram/
	int largestRectangleArea_stack(vector<int>& heights) {
		int rs = 0;
		stack<int>st;
		heights.push_back(0);
		for (int i = 0; i<heights.size(); i++) {
			if (st.empty() || heights[st.top()] <= heights[i])
				st.push(i);
			else {
				//cur Ϊ��i-1Ϊֹ����С��ֵ

				int cur = st.top();
				st.pop();
				//���ջΪ�գ�cur���Ǵӿ�ʼΪֹ����Сֵ��length=i����
				int length = i;
				if (!st.empty())
					length = i - st.top() - 1;
				rs = max(rs, heights[cur] * length);
				--i;
			}
		}
		return rs;

	}

	int largestRectangleArea(vector<int>& heights) {
		int rs = 0;
		int n = heights.size();
		for (int i = 0; i<n; i++) {
			if (i + 1<n&&heights[i] <= heights[i + 1])
				continue;
			int min_val = heights[i];
			for (int j = i; j >= 0; j--) {
				min_val = min(min_val, heights[j]);
				rs = max(rs, min_val*(i - j + 1));
			}
		}
		return rs;

	}
};