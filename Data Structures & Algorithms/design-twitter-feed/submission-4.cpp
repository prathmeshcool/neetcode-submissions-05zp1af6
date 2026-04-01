class Twitter {
public:
    int time=0;
    unordered_map<int,unordered_set<int>> mp;
    unordered_map<int,vector<pair<int,int>>> mp2;

    Twitter() {
        time=0;
        mp.clear();
        mp2.clear();
    }

    void postTweet(int userId, int tweetId) {
        mp2[userId].push_back({time++, tweetId});
    }   

    vector<int> getNewsFeed(int userId) {
        
        unordered_set<int>s=mp[userId];
        s.insert(userId);

        priority_queue<vector<int>> pq;

        for(auto uid:s){
            if(mp2[uid].size()){
                int id = mp2[uid].size()-1;
                auto [time, tweetId] = mp2[uid][id];
                pq.push({time, uid, tweetId, id});
            }
        }
        vector<int> ans;
        while(pq.size() && ans.size()!=10){

            auto v = pq.top();pq.pop();
            int uid=v[1];
            int tweetId=v[2];
            int id=v[3];
            ans.push_back(tweetId);

            if(id>0){
                auto [time, tweetId]=mp2[uid][id-1];
                pq.push({time,uid,tweetId,id-1});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};
