class Twitter {
public:
 int count = 0;
    unordered_map<int,vector<pair<int,int>>>posts;
    map<pair<int,int>,int>follower;

    Twitter() {}
   
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({count,tweetId});
        count++;
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> v;
        vector<pair<int,int>>v1;
        vector<int>ans;
        v.insert(userId);
        for(auto i:follower){
            if(i.first.first == userId && i.second>0) v.insert(i.first.second);
        }
        for(auto i:v){
            v1.insert(v1.end(),posts[i].begin(),posts[i].end());
        }
        sort(v1.rbegin(),v1.rend());
        for(auto i:v1){
            if (ans.size() == 10) break;
            ans.push_back(i.second);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follower[{followerId,followeeId}]++;
    }

    void unfollow(int followerId, int followeeId) {
        if(follower[{followerId,followeeId}]) follower[{followerId,followeeId}]--;
    }
};