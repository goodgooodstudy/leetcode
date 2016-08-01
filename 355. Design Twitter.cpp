class Twitter {

public:
    struct Tweet{
        int time;
        int id;
        Tweet(int t, int id):time(t),id(id){}
    };
    unordered_map<int,unordered_set<int>> followees;
    unordered_map<int, vector<Tweet>> tweets;
    int time;
    /** Initialize your data structure here. */
    Twitter():time(0) {
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(time++,tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto cmp = [](Tweet& a, Tweet& b){return a.time < b.time;};
        priority_queue <Tweet, vector<Tweet>,decltype(cmp)> max_heap(cmp);
        unordered_set<int> getslist = followees[userId];
        getslist.insert(userId);
        for(auto followee:getslist){
            int n = tweets[followee].size();
            for(int i = n-1; i>= 0 && i>=n-10; i--){
                max_heap.push(tweets[followee][i]);
            }
        }
        int n = 10;
        while(n-->0 &&!max_heap.empty()){
            Tweet cur = max_heap.top();
            max_heap.pop();
            res.push_back(cur.id);
        }
        return res;
        
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        else{
            // if(!followees.count(followerId)) followees[followerId]=vector<int>();
            followees[followerId].insert(followeeId); //if followerId first time;
        }
        
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        // if(!followees.count(followerId)) return;
        followees[followerId].erase(followeeId);
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
