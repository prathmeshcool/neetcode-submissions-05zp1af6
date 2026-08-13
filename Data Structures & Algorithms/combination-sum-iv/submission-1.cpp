class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1, 0);

        sort(nums.begin(), nums.end());


        dp[0] = 1;

        for(int i=1; i<=target; i++){
            for(int j=0; j<n; j++){
                if(nums[j]>i)break;
                int need = i - nums[j];
                dp[i]+=dp[need];
            }
        }

        return dp[target];
    }
};