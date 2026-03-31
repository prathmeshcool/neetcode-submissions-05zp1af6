class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        int dp[n], ans=1;
        dp[0]=1;
        for(int i=1; i<n; i++){
            int mx = INT_MIN;
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i])
                    mx = max(mx, dp[j]);
            }
            dp[i]=max(mx+1, 1);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
