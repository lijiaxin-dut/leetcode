#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

//Design a simplified version of Twitter where users can post tweets, follow / unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:
//
//postTweet(userId, tweetId) : Compose a new tweet.
//getNewsFeed(userId) : Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
//follow(followerId, followeeId) : Follower follows a followee.
//unfollow(followerId, followeeId) : Follower unfollows a followee.
//Example :


//使用优先队列对按照时间排序
//返回时间最大的10条消息
//time模拟时间
//postTweet时，首先添加用户，使得自己关注自己
//方便返回消息

class Twitter {
	
public:
	unordered_map<int, unordered_set<int>>users;
	unordered_map<int, vector<pair<int, int>>>tweets;
	int time = 0;
	/** Initialize your data structure here. */
	Twitter() {

	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		follow(userId, userId);
		tweets[userId].push_back(make_pair(time++, tweetId));
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		auto compare = [](pair<int, int> a, pair<int, int> b) {return a.first<b.first; };
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)>pq(compare);
		for (auto &one_follows : users[userId]) {
			for (auto &one_tweet : tweets[one_follows])
				pq.push(make_pair(one_tweet.first, one_tweet.second));

		}
		//for (auto &one_tweet : tweets[userId])
			//pq.push(make_pair(one_tweet.first, one_tweet.second));
		vector<int>rs;
		while (!pq.empty() && rs.size()<10) {
			rs.push_back(pq.top().second);
			pq.pop();
		}
		return rs;


		

	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		users[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (followerId != followeeId)
			users[followerId].erase(followeeId);
	}
};

/**
* Your Twitter object will be instantiated and called as such:
* Twitter* obj = new Twitter();
* obj->postTweet(userId,tweetId);
* vector<int> param_2 = obj->getNewsFeed(userId);
* obj->follow(followerId,followeeId);
* obj->unfollow(followerId,followeeId);
*/
//
//int main() {
//	Twitter twitter ;
//	// User 1 posts a new tweet (id = 5).
//	twitter.postTweet(1, 5);
//
//	// User 1's news feed should return a list with 1 tweet id -> [5].
//	twitter.getNewsFeed(1);
//
//	// User 1 follows user 2.
//	twitter.follow(1, 2);
//
//	// User 2 posts a new tweet (id = 6).
//	twitter.postTweet(2, 6);
//
//	// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
//	// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
//	twitter.getNewsFeed(1);
//
//	// User 1 unfollows user 2.
//	twitter.unfollow(1, 2);
//
//	// User 1's news feed should return a list with 1 tweet id -> [5],
//	// since user 1 is no longer following user 2.
//	twitter.getNewsFeed(1);
//}