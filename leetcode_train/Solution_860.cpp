#include<vector>
#include<unordered_map>

using namespace std;


//At a lemonade stand, each lemonade costs $5.
//
//Customers are standing in a queue to buy from you, and order one at a time(in the order specified by bills).
//
//Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.You must provide the correct change to each customer, so that the net transaction is that the customer pays $5.
//
//Note that you don't have any change in hand at first.
//
//Return true if and only if you can provide every customer with correct change.



class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		unordered_map<int, int>count;
		for (int i = 0; i<bills.size(); i++) {
			if (bills[i] == 5)
				count[5]++;
			else if (bills[i] == 10) {
				count[10]++;
				count[5]--;
			}
			else {
				count[20]++;
				if (count[10]>0) {
					count[10]--;
					count[5]--;
				}
				else {
					count[5] -= 3;
				}

			}

			if (count[5]<0 || count[10]<0)
				return false;
		}
		return true;
	}
};