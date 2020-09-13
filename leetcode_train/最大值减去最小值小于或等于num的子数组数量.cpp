//#include<iostream>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
//int main() {
//	vector<int>arrays;
//	int n, nums;
//	cin >> n >> nums;
//	int rs = 0;
//	deque<int>qmin;
//	deque<int>qmax;
//	for (int i = 0; i < n; i++) {
//		int temp;
//		cin >> temp;
//		arrays.push_back(temp);
//	}
//	int i = 0;
//	int j = 0;
//	while (i < arrays.size()) {
//		while (j < arrays.size()) {
//			while (!qmax.empty() && arrays[j] >= arrays[qmax.back()]) {
//				qmax.pop_back();
//			}
//			qmax.push_back(j);
//			while (!qmin.empty() && arrays[j] <= arrays[qmin.back()]) {
//				qmin.pop_back();
//			}
//			qmin.push_back(j);
//			if (arrays[qmax.front()] - arrays[qmin.front()] > nums)
//				break;
//			j++;
//		}
//		if (qmax.front() == i)
//			qmax.pop_front();
//		if (qmin.front() == i)
//			qmin.pop_front();
//		rs += j - i;//当前的子数组中包含i
//		i++;
//	}
//	cout << rs;
//
//		
//}