#include<vector>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;

class Solution {
	int count_char(string IP, char c) {
		int rs = 0;
		for (auto &one_char : IP) {
			if (one_char == c)
				rs++;
		}
		return rs;

	}
	vector<string> split(string IP, char c) {
		vector<string> rs;
		stringstream ss(IP);
		while (getline(ss, IP, c)) {
			rs.push_back(IP);
		}
		return rs;
	}
public:
	string validIPAddress(string IP) {
		if (IP.find('.') != std::string::npos) {
			vector<string>s = split(IP, '.');
			int n = count_char(IP, '.');
			if (s.size() != 4 || n != 3)
				return "Neither";
			try {
				for (int i = 0; i<4; i++) {
					//没有数字不合法
					if (s[i].empty())
						return "Neither";
					//前导0不合法
					if (s[i][0] == '0'&&stoi(s[i]) != 0)
						return "Neither";
					//超出范围不合法
					if (stoi(s[i])<0 || stoi(s[i])>255 || s[i].size() != to_string(stoi(s[i])).size())
						return "Neither";
				}
				return "IPv4";
			}
			catch (...) {
				return "Neither";

			}

		}
		else if (IP.find(':') != std::string::npos) {
			//IPV6
			vector<string>s = split(IP, ':');
			int n = count_char(IP, ':');
			if (s.size() != 8 || n != 7)
				return "Neither";
			for (int i = 0; i<8; i++) {
				if (s[i].size()>4 || s[i].size() <= 0)
					return "Neither";
				for (int j = 0; j<s[i].size(); j++) {
					if (!((s[i][j] >= '0'&&s[i][j] <= '9') || (s[i][j] >= 'A'&&s[i][j] <= 'F') || (s[i][j] >= 'a'&&s[i][j] <= 'f')))
						return "Neither";
				}
			}
			return "IPv6";

		}
		else {
			return "Neither";
		}
	}
};
