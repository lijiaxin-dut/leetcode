#include<string>
#include<vector>

using namespace std;

//Write a program that outputs the string representation of numbers from 1 to n.
//
//But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”.For numbers which are multiples of both three and five output “FizzBuzz”.
//
//Example:
//
//n = 15,
//
//Return :
//	[
//		"1",
//		"2",
//		"Fizz",
//		"4",
//		"Buzz",
//		"Fizz",
//		"7",
//		"8",
//		"Fizz",
//		"Buzz",
//		"11",
//		"Fizz",
//		"13",
//		"14",
//		"FizzBuzz"
//	]


//分情况讨论或者在内部奇数


class Solution {
public:
	vector<string> fizzBuzz_(int n) {
		vector<string> rs;
		for (int i = 1; i <= n; ++i) {
			if (i % 15 == 0)
				rs.push_back("FizzBuzz");
			else if (i % 3 == 0)
				rs.push_back("Fizz");
			else if (i % 5 == 0)
				rs.push_back("Buzz");
			else
				rs.push_back(to_string(i));
		}
		return rs;
	}

	vector<string> fizzBuzz(int n) {
		vector<string> rs;
		int fizz = 0;
		int buzz = 0;
		for (int i = 1; i <= n; ++i) {
			fizz++;
			buzz++;
			if (fizz == 3 && buzz == 5) {
				rs.push_back("FizzBuzz");
				fizz = 0;
				buzz = 0;
			}
			else if (fizz == 3) {
				rs.push_back("Fizz");
				fizz = 0;
			}
			else if (buzz == 5) {
				rs.push_back("Buzz");
				buzz = 0;
			}
			else {
				rs.push_back(to_string(i));
			}
		}
		return rs;
	}
};