class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        if(mp.size()!=nums.size()){
            return true;
        }
        return false;
    
    }
};