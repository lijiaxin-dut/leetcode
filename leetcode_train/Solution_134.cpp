#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<memory>
#include<unordered_map>
#include<set>


using namespace std;


//There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
//
//You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station(i + 1).You begin the journey with an empty tank at one of the gas stations.
//
//Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.
//
//Note:
//
//If there exists a solution, it is guaranteed to be unique.
//Both input arrays are non - empty and have the same length.
//Each element in the input arrays is a non - negative integer.
//Example 1 :
//
//	Input :
//	gas = [1, 2, 3, 4, 5]
//	cost = [3, 4, 5, 1, 2]
//
//	Output : 3
//
//	Explanation :
//	Start at station 3 (index 3) and fill up with 4 unit of gas.Your tank = 0 + 4 = 4
//	Travel to station 4. Your tank = 4 - 1 + 5 = 8
//	Travel to station 0. Your tank = 8 - 2 + 1 = 7
//	Travel to station 1. Your tank = 7 - 3 + 2 = 6
//	Travel to station 2. Your tank = 6 - 4 + 3 = 5
//	Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
//	Therefore, return 3 as the starting index.
//	Example 2:
//
//Input:
//gas = [2, 3, 4]
//cost = [3, 4, 3]
//
//Output : -1
//
//	Explanation :
//	You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
//	Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
//	Travel to station 0. Your tank = 4 - 3 + 2 = 3
//	Travel to station 1. Your tank = 3 - 3 + 3 = 3
//	You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
//	Therefore, you can't travel around the circuit once no matter where you start.
//

//
//If car starts at A and can not reach B.Any station between A and B
//can not reach B.(B is the first station that A can not reach.)

//从A出发，证明A点的存储一定大于消耗，差值是个正数
//若从A到B差值求和未负数，A-B中间的任意一点作为起点都不能到达B点



//如果所有的gas-cost求和大于0，一定存在一个解
//类似于max_subarray
//如果求和大于0并且存在一个点到终点的gas-cost求和大于0，这个点就是结果


class Solution_134 {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

		int current_sum = 0;
		int total = 0;
		int start = 0;
		for (int i = 0; i<gas.size(); i++) {
			int dis = gas[i] - cost[i];
			current_sum += dis;
			total += dis;
			if (current_sum<0) {
				start = i + 1;
				current_sum = 0;
			}
		}
		if (total<0)
			return -1;
		return start;
	}
};