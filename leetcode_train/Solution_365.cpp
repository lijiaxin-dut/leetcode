#include<queue>
#include<set>

using namespace std;

//You are given two jugs with capacities x and y litres.There is an infinite amount of water supply available.You need to determine whether it is possible to measure exactly z litres using these two jugs.
//
//If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.
//
//Operations allowed :
//
//Fill any of the jugs completely with water.
//Empty any of the jugs.
//Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
//Example 1 : (From the famous "Die Hard" example)
//
//Input : x = 3, y = 5, z = 4
//	Output : True

//BFS±éÀúËùÓĞ¿ÉÄÜ
//¹²ÓĞÁùÖÖ²Ù×÷
//µ¹¿Õcur_x
//µ¹¿Õcur_y
//µ¹Âúcur_x
//µ¹Âúcur_y
//cur_x->cur_y
//cur_y->cur_x



class Solution {
public:
	bool canMeasureWater(int x, int y, int z) {
		if (x + y<z)
			return false;
		if (x == 0 || y == 0)
			return x == z || y == z;
		queue<pair<int, int>>q;
		set<pair<int, int>>visited;
		q.push(make_pair(0, 0));
		visited.insert(make_pair(0, 0));
		while (!q.empty()) {
			auto cur_x = q.front().first;
			auto cur_y = q.front().second;
			q.pop();
			if (cur_x == z || cur_y == z || cur_x + cur_y == z)
				return true;
			//µ¹¿Õx
			pair<int, int>p1 = make_pair(0, cur_y);
			if (visited.find(p1) == visited.end()) {
				q.push(p1);
				visited.insert(p1);
			}
			//µ¹¿Õy
			pair<int, int>p2 = make_pair(cur_x, 0);
			if (visited.find(p2) == visited.end()) {
				q.push(p2);
				visited.insert(p2);
			}
			//µ¹Âúx
			pair<int, int>p3 = make_pair(x, cur_y);
			if (visited.find(p3) == visited.end()) {
				q.push(p3);
				visited.insert(p3);
			}
			//µ¹Âúy
			pair<int, int>p4 = make_pair(cur_x, y);
			if (visited.find(p4) == visited.end()) {
				q.push(p4);
				visited.insert(p4);
			}
			//xµ¹Èëy
			pair<int, int>p5 = make_pair(max(0,cur_x-(y-cur_y)), min(y,cur_x+cur_y));
			if (visited.find(p5) == visited.end()) {
				q.push(p5);
				visited.insert(p5);
			}
			//yµ¹Èëx
			pair<int, int>p6 = make_pair(min(x,cur_x+cur_y),max(0,cur_y-(x-cur_x)));
			if (visited.find(p6) == visited.end()) {
				q.push(p6);
				visited.insert(p6);
			}
		}
		return false;
	}
};