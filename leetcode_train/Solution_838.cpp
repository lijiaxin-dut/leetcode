#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//一行中有 N 张多米诺骨牌，我们将每张多米诺骨牌垂直竖立。

//在开始时，我们同时把一些多米诺骨牌向左或向右推。
//
//每过一秒，倒向左边的多米诺骨牌会推动其左侧相邻的多米诺骨牌。
//
//同样地，倒向右边的多米诺骨牌也会推动竖立在其右侧的相邻多米诺骨牌。
//
//如果同时有多米诺骨牌落在一张垂直竖立的多米诺骨牌的两边，由于受力平衡， 该骨牌仍然保持不变。

//如果我们有 "A....B"，当 A = B，那么就变成 "AAAAAA"。
//如果我们有 "R....L"，那么结果会变成 "RRRLLL" 或者 "RRR.LLL" 如果点的个数是奇数。
//如果初始标记的坐标是 i 和 j，我们可以检查距离 k - i 和 j - k 来决定位置 k 的形态是 'L'，'R' 还是 '.'。
//如果我们有 "L....R"，就什么都不做，跳过。

//端点添加辅助字母，用于处理特殊情况
//当遇到一组端点时，只考虑左端点，右端点不加入到rs中

//需要注意添加的长度，不要越界


class Solution_838 {
public:
	string pushDominoes(string dominoes) {
		dominoes = "L" + dominoes + "R";
		int last_index = 0;
		char last_letter = 'L';
		string rs;
		for (int i = 1; i<dominoes.size(); i++) {
			//跳过所有的.
			if (dominoes[i] == '.')
				continue;
			//当前位置是L
			if (dominoes[i] == 'L') {
				//之前的位置是L
				if (last_letter == 'L')
					rs += string(i - last_index, 'L');
				//之前的位置是R
				else {
					int length = i - last_index + 1;
					rs += string(length / 2, 'R');
					if (length % 2 != 0)
						rs += ".";
					rs += string(length / 2 - 1, 'L');
				}
				last_letter = 'L';
			}
			//当前位置时R
			else if (dominoes[i] == 'R') {
				//之前的位置是
				if (last_letter == 'L') {
					rs += "L";
					rs += string(i - last_index - 1, '.');
				}
				//之前的位置是R
				else
					rs += string(i - last_index, 'R');
				last_letter = 'R';
			}
			last_index = i;
		}
		rs.erase(rs.begin());
		return rs;
	}
};

//int main() {
//	Solution_838 s;
//	s.pushDominoes(".L.R...LR..L..");
//}