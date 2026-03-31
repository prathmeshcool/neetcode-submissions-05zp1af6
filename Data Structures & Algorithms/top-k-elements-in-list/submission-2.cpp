class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
       
        vector<vector<int>> v(nums.size()+1);
        
        for(auto x:mp){
            v[x.second].push_back(x.first);
        }
        vector<int> ans;
        for(int i=nums.size(); i>=0 && ans.size()<k; i--){
            for(int j:v[i]){
                ans.push_back(j);
            }
        }


        return ans;

    }
};
