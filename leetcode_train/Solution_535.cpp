#include<string>
#include<unordered_map>
#include<utility>
#include<iostream>
#include<functional>
using namespace std;



class Solution {
	unordered_map<string, string>hash_map;
public:

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		string short_url = "https://" + to_string(std::hash<string>{}(longUrl));
		hash_map[short_url] = longUrl;
		return short_url;
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		return hash_map[shortUrl];
	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));


\