class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int>> mp;
        int n = nums.size();
        for(int i=0;i<n; i++){
            mp[nums[i]].push_back(i);
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(nums[i]==target-nums[i] && mp[nums[i]].size()>1){
                cout<<mp[nums[i]].size()<<endl;
                ans.push_back(i);
                ans.push_back(mp[nums[i]][1]);
                return ans;
            }
            if(mp.count(target-nums[i]) && nums[i]!=target-nums[i]){
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]][0]);
                return ans;
            }
        }
    }
};
