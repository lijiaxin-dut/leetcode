#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution_67 {
public:
	string addBinary(string a, string b) {
		int a_size = a.size();
		int b_size = b.size();
		if (a_size == 0)
			return b;
		if (b_size == 0)
			return a;
		int a_index = a_size - 1;
		int b_index = b_size - 1;
		string rs;
		int carry = 0;
		while (a_index >= 0 && b_index >= 0) {
			int temp = (a[a_index] - '0') + (b[b_index] - '0') + carry;
			carry = temp / 2;
			rs.push_back(temp % 2 + '0');
			a_index--;
			b_index--;
		}

		while (a_index >= 0) {
			int temp = (a[a_index] - '0') + carry;
			carry = temp / 2;
			rs.push_back(temp % 2 + '0');
			a_index--;
		}
		while (b_index >= 0) {
			int temp = (b[b_index] - '0') + carry;
			carry = temp / 2;
			rs.push_back(temp % 2 + '0');
			b_index--;
		}
		if (carry>0)
			rs.push_back(carry + '0');
		reverse(rs.begin(), rs.end());
		return rs;
	}
};
