#include<unordered_map>

using namespace std;


//You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones.The one who removes the last stone will be the winner.You will take the first turn to remove the stones.
//
//Both of you are very clever and have optimal strategies for the game.Write a function to determine whether you can win the game given the number of stones in the heap.
//
//Example :
//
//	Input : 4
//	Output : false
//	Explanation : If there are 4 stones in the heap, then you will never win the game;
//No matter 1, 2, or 3 stones you remove, the last stone will always be
//removed by your friend.



//�õ����һ��ʯ�ӵ��˻�ʤ
//ֻҪ�ܱ�4��������һ�����䣬�����Ӯ



//dfs������еĿ����ԣ�����ÿһ����ʯͷ���������п����õĿ���

class Solution_292 {
public:
	class Solution {
		unordered_map<int, bool>table;
	public:
		bool canWinNim_dfs(int n) {
			return dfs(n);
		}
		bool dfs(int n) {
			if (table.count(n))
				return table[n];
			if (n <= 3)
				return true;
			for (int i = 1; i <= 3; i++) {
				if (!dfs(n - i)) {
					table[n] = true;
					return true;
				}
			}
			table[n] = false;
			return false;
		}
	};

	bool canWinNim(int n) {
		return n % 4;
	}
};