#include<vector>
#include<queue>

using namespace std;


//There are N rooms and you start in room 0.  Each room has a distinct number in 0, 1, 2, ..., N - 1, and each room may have some keys to access the next room.
//
//Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in[0, 1, ..., N - 1] where N = rooms.length.A key rooms[i][j] = v opens the room with number v.
//
//Initially, all the rooms start locked(except for room 0).
//
//You can walk back and forth between rooms freely.
//
//Return true if and only if you can enter every room.

//bfs

class Solution_841 {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		int n = rooms.size();
		vector<bool>mark(n, false);
		queue<int>q;
		q.push(0);
		mark[0] = true;
		int open_number = 1;
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			for (auto out_edge : rooms[t]) {
				if (mark[out_edge] == false) {
					mark[out_edge] = true;
					q.push(out_edge);
					open_number++;
				}
			}
		}
		return open_number == n;

	}
};