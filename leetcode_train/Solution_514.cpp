#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

//In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring", and use the dial to spell a specific keyword in order to open the door.
//
//Given a string ring, which represents the code engraved on the outer ring and another string key, which represents the keyword needs to be spelled.You need to find the minimum number of steps in order to spell all the characters in the keyword.
//
//Initially, the first character of the ring is aligned at 12:00 direction.You need to spell all the characters in the string key one by one by rotating the ring clockwise or anticlockwise to make each character of the string key aligned at 12 : 00 direction and then by pressing the center button.
//
//At the stage of rotating the ring to spell the key character key[i] :
//
//	You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step.The final purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, where this character must equal to the character key[i].
//	If the character key[i] has been aligned at the 12 : 00 direction, you need to press the center button to spell, which also counts as 1 step.After the pressing, you could begin to spell the next character in the key(next stage), otherwise, you've finished all the spelling.


//1.dfs+memory  对于每一个位置，正方向走一半的长度，反方向走一半的长度
//2.dp



class Solution {
	vector<vector<int>>c;
public:
	int findRotateSteps(string ring, string key) {
		int n = ring.size();
		int m = key.size();
		int half_length = (n + 1) / 2;
		c.resize(n, vector<int>(m, -1));
		return dfs(ring, key, 0, 0, half_length);
	}
	int dfs(string &ring, string &key, int ring_index, int key_index, int half_length) {
		if (key_index == key.size())
			return 0;
		int n = ring.size();
		int rs = INT_MAX;
		if (c[ring_index][key_index] != -1)
			return c[ring_index][key_index];
		//正方向
		for (int i = 0; i <= half_length; i++) {
			int next_index = (ring_index + i) % n;
			if (key[key_index] == ring[next_index])
				rs = min(rs, 1 + i + dfs(ring, key, next_index, key_index + 1, half_length));
		}
		//反方向
		for (int i = 0; i <= half_length; i++) {
			int next_index = (ring_index - i + n) % n;
			if (key[key_index] == ring[next_index])
				rs = min(rs, 1 + i + dfs(ring, key, next_index, key_index + 1, half_length));
		}
		c[ring_index][key_index] = rs;
		return rs;

	}
};