class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end(),greater<>());
        double req = -1;
        int fleet = 0;
        for(int i=0; i<n; i++){
            double time = (target-v[i].first)*1.0/v[i].second;
            if(time>req){
                fleet++;
                req = time;
            }
        }
        return fleet;
    }
};
