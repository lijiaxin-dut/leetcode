#include<vector>

using namespace std;


//Given an array of scores that are non - negative integers.Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on.Each time a player picks a number, that number will not be available for the next player.This continues until all the scores have been chosen.The player with the maximum score wins.
//
//Given an array of scores, predict whether player 1 is the winner.You can assume each player plays to maximize his score.
//自定向下递归


class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int left_avalible = 0;
		int right_avalible = nums.size() - 1;
		return  help(0, left_avalible, right_avalible, 0, 0, nums);

	}
	bool help(int turn, int left_avalible, int right_avalible, int first_score, int second_score, vector<int>& nums) {
		if (left_avalible>right_avalible) {
			return first_score>second_score;
		}

		if (turn % 2 == 1) {
			//second。不管player 2选择哪一边，都是player赢才行
			return help(turn + 1, left_avalible + 1, right_avalible, first_score, second_score + nums[left_avalible], nums)
				&& help(turn + 1, left_avalible, right_avalible - 1, first_score, second_score + nums[right_avalible], nums);

		}
		else {
			//player 1只要有一边赢就可以
			return help(turn + 1, left_avalible + 1, right_avalible, first_score + nums[left_avalible], second_score, nums)
				|| help(turn + 1, left_avalible, right_avalible - 1, first_score + nums[right_avalible], second_score, nums);

		}
	}
};

