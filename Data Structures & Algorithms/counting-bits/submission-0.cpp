class Solution {
public:
    vector<int> countBits(int n) {
        int dp[n+1];
        dp[0]=0;

        int currPower = 0;
        vector<int> ans;
        ans.push_back(0);

        for(int i=1; i<=n; i++){
            if((i&(i-1))==0){
                currPower = i;
            }
            dp[i]=dp[i-currPower]+1;
            ans.push_back(dp[i]);
        }

        return ans;
    }
};
