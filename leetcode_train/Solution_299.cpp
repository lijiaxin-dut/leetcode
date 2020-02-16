#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

//You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is.Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position(called "bulls") and how many digits match the secret number but locate in the wrong position(called "cows").Your friend will use successive guesses and hints to eventually derive the secret number.
//
//Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 
//
//Please note that both secret number and friend's guess may contain duplicate digits.

//猜数游戏

//统计不想同时，每个数字出现的个数,遍历不相同的数字，两者取较小值
//加入0在secret出现了两次，在guess出现了三次
//则取2




class Solution_299 {
public:
	string getHint(string secret, string guess) {
		string rs;
		int bull = 0;
		vector<int>mark_s(10);
		vector<int>mark_g(10);
		for (int i = 0; i<guess.size(); i++) {
			if (secret[i] == guess[i])
				bull++;
			else {
				mark_s[secret[i] - '0']++;
				mark_g[guess[i] - '0']++;
			}
		}
		int cow = 0;
		for (int i = 0; i<mark_s.size(); i++) {
			cow += min(mark_s[i], mark_g[i]);
		}
		return to_string(bull) + "A" + to_string(cow) + "B";
	}
};