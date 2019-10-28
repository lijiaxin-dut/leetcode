#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

//Suppose you have a random list of people standing in a queue.Each person is described by a pair of integers(h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h.Write an algorithm to reconstruct the queue.
//
//Note:
//The number of people is less than 1, 100.
//
//
//Example
//
//Input :
//[[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]
//
//Output :
//	[[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]

//���յ�һ��Ԫ�شӴ�С���򣬵�һ��Ԫ����ͬʱ�����յڶ���Ԫ�ش�С��������
//�������������飬���ϵİ��յڶ���Ԫ�ص�ֵ����




class Solution_406 {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

		sort(people.begin(), people.end(), [](vector<int>a, vector<int>b) {
			return a[0]>b[0] || (a[0] == b[0] && a[1]<b[1]);
		});

		vector<vector<int>>rs;
		for (auto &one_people : people) {
			rs.insert(rs.begin() + one_people[1], one_people);
		}

		return rs;



	}
};

