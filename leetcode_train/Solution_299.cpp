#include<string>
#include<unordered_map>

using namespace std;

//You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is.Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position(called "bulls") and how many digits match the secret number but locate in the wrong position(called "cows").Your friend will use successive guesses and hints to eventually derive the secret number.
//
//Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 
//
//Please note that both secret number and friend's guess may contain duplicate digits.

//猜数游戏
//使用map进行标记
//两次循环


class Solution_299 {
public:
	string getHint(string secret, string guess) {
		string rs;
		int bull = 0;
		unordered_map<char, int>mark_s;
		unordered_map<char, int>mark_g;
		for (int i = 0; i<guess.size(); i++) {
			if (secret[i] == guess[i])
				bull++;
			else {
				mark_s[secret[i]]++;
				mark_g[guess[i]]++;
			}
		}
		int cow = 0;
		if (mark_s == mark_g)
			cow = guess.size() - bull;
		else {
			for (int i = 0; i<guess.size(); i++) {
				if (secret[i] != guess[i] && mark_s.find(guess[i]) != mark_s.end() && mark_s[guess[i]]>0) {
					mark_s[guess[i]]--;
					cow++;
				}
			}
		}
		return to_string(bull) + "A" + to_string(cow) + "B";
	}
};