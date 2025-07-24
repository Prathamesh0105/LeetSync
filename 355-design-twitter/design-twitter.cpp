class Twitter {
private:
int time;
unordered_map<int,set<pair<int,int>>>user_tweets;
unordered_map<int,unordered_set<int>>user_follow;
public:
    Twitter() {  
        time = 0;
    } 
    void postTweet(int userId, int tweetId) {
        user_tweets[userId].insert({-time,tweetId});
        time++;
    }
    vector<int> getNewsFeed(int userId) { 
        vector<int>ans;
        using pii = pair<int,int>;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        int count = 0;
        for(auto it = user_tweets[userId].begin();it!=user_tweets[userId].end() && count<10;it++){
            int a = it->first,b = it->second;
            a*=-1;
            if(pq.size() < 10){
                pq.push({a,b});
            }
            else if(pq.size()>=10){
                pii x = pq.top();
                if(x.first < a){
                    pq.pop();
                    pq.push({a,b});
                }
            }
            count++;
        }
        for(auto &i:user_follow[userId]){
            count = 0;
            for(auto it = user_tweets[i].begin();it!=user_tweets[i].end() && count<10;it++){
                int a = it->first,b = it->second;
                a*=-1;
                if(pq.size() < 10){
                    pq.push({a,b});
                }
                else if(pq.size()>=10){
                    pii x = pq.top();
                    if(x.first < a){
                        pq.pop();
                        pq.push({a,b});
                    }
                }
                count++;
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        user_follow[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(user_follow.count(followerId) > 0){
            if(user_follow[followerId].find(followeeId)!=user_follow[followerId].end()){
                user_follow[followerId].erase(followeeId);
            }
        }
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