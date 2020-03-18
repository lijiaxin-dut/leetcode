#include<vector>
#include<algorithm>

using namespace std;

//We distribute some number of candies, to a row of n = num_people people in the following way :
//
//We then give 1 candy to the first person, 2 candies to the second person, and so on until we give n candies to the last person.
//
//Then, we go back to the start of the row, giving n + 1 candies to the first person, n + 2 candies to the second person, and so on until we give 2 * n candies to the last person.
//
//This process repeats(with us giving one more candy each time, and moving to the start of the row after we reach the end) until we run out of candies.The last person will receive all of our remaining candies(not necessarily one more than the previous gift).
//
//Return an array(of length num_people and sum candies) that represents the final distribution of candies.


//Ñ­»·±éÀú¼´¿É

class Solution {
public:
	vector<int> distributeCandies_1(int candies, int num_people) {
		vector<int> rs(num_people, 0);
		for (int i = 0; candies > 0; ++i) {
			rs[i % num_people] += min(candies, i + 1);
			candies -= i + 1;
		}
		return rs;
	}
	vector<int> distributeCandies(int candies, int num_people) {
		vector<int>rs(num_people, 0);
		int iter_time = 0;
		while (candies>0) {
			for (int i = 1; i <= num_people&&candies>0; i++) {
				rs[i - 1] += min(i + iter_time*num_people, candies);
				candies -= i + iter_time*num_people;
			}
			iter_time++;
		}
		return rs;
	}
};