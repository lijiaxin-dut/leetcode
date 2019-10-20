
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

//��������1��n��ʯ��ʱ����ô����Ϊ(n + 1)��������ʱһ�����䣬��������֤��һ��������ۣ�����ǰ����m*(n + 1)��ʯ�ӣ���ô��
//
//��m = 1ʱ����ʣn + 1����ʱ�򣬿϶����䣬��Ϊ������ȡ1��n�е��κ�һ�����֣���һ���˶�����ȡ�ꡣ
//��m>1ʱ������m*(n + 1)��ʱ�򣬲�������ȡ1��n�е��κ�һ������x������һ����һ����ȡn + 1 - x����
//���������ͱ����(m - 1)*(n + 1)���ڶ����˾�һֱ���������ȡ����ôֱ��ʣn + 1����ʱ��
//�ͱ���m = 1�������һ�����䡣


class Solution_292 {
public:
	bool canWinNim(int n) {
		return n % 4;
	}
};