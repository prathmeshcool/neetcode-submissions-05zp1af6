class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
       
       priority_queue<pair<int,int>> pq;

       for(auto x:mp){
            pq.push({x.second,x.first});           
       }
        vector<int>ans;
        while(k>0){
            pair<int,int> x = pq.top();
            ans.push_back(x.second);
            pq.pop();
            k--;
        }
        return ans;


        

    }
};
