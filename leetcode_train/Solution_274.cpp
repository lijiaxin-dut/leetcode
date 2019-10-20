#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

//Given an array of citations(each citation is a non - negative integer) of a researcher, write a function to compute the researcher's h-index.
//
//According to the definition of h - index on Wikipedia : "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."



//至多有 h 篇论文分别被引用了至少 h 次

//h篇论文，被引用了h次

//从大到小排序
//找到第一个i>=num[i]的即可




class Solution_274 {
public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end(), greater<int>());
		for (int i = 0; i<citations.size(); i++) {
			if (i >= citations[i])
				return i;
		}
		return citations.size();

	}
};