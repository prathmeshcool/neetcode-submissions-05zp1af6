class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1, 0);

        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }


        for(int i=1; i<=target; i++){
            if(mp[i]>0)dp[i]=1;
            for(int j=0; j<n; j++){
                if(nums[j]>=i)break;
                int need = i - nums[j];
                dp[i]+=dp[need];
            }
            cout<<dp[i]<<" ";
        }

        return dp[target];
    }
};