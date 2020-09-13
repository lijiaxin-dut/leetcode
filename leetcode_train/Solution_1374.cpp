#include<string>

using namespace std;

class Solution {
public:
	string generateTheString(int n) {
		return help(n, 'a');
	}
	string help(int n, char a) {
		if (n % 2 == 1)
			return string(n, a);
		else
			return string(n - 1, a) + help(1, a + 1);
	}
};