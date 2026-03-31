class Solution {
public:

    bool subset(int i, int sum, int target, vector<vector<int>> &dp, vector<int> &nums){
        if(sum>target)
            return false;
        if(sum==target)
            return true;
        if(i<0)
            return false;
        if(dp[i][sum]!=-1)
            return dp[i][sum];

        bool chk = false;
        
        for(int j=i; j>=0; j--){
            chk = chk || subset(j-1, sum+nums[j], target, dp, nums);
        }

        return dp[i][sum]=chk;


    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(sum, -1));

        if(sum%2){
            return false;
        }
        return subset(n-1, 0, sum/2, dp, nums);
    }
};
