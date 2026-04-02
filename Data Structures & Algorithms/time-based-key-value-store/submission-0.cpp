class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        
        if(mp[key].empty())
            return "";

        auto &v = mp[key];

        int n = v.size();

        int l=0, r=n-1;
        string ans="";
        while(l<=r){
            int mid = l+(r-l)/2;
            auto [t, val]=v[mid];
            if(t==timestamp){
                return val;
            }
            else if(t<timestamp){
                ans=val;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;
    }
};
