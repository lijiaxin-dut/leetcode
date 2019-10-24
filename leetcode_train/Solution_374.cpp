//We are playing the Guess Game.The game is as follows :
//
//I pick a number from 1 to n.You have to guess which number I picked.
//
//Every time you guess wrong, I'll tell you whether the number is higher or lower.
//
//You call a pre - defined API guess(int num) which returns 3 possible results(-1, 1, or 0) :
//
//	-1 : My number is lower
//	1 : My number is higher
//	0 : Congrats!You got it!
//

//¶þ·ÖËÑË÷


int guess(int num);


class Solution_374 {
public:
	int guessNumber(int n) {

		int left = 1;
		int right = n;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			int t = guess(mid);
			if (t == 0)
				return mid;
			else if (t == 1)
				left = mid + 1;
			else
				right = mid - 1;
			}
		return 0;


	}
};