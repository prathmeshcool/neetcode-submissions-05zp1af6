class Solution {
public:
    int numSquares(int n) {
        vector<int> dp (n+1, INT_MAX);
        for(int i=1; i<=sqrt(n); i++){
            int sq = i*i;
            dp[sq] = 1;
        }
        dp[0]=0;

        for(int i=1; i<=n; i++){
            // if(dp[i]!=INT_MAX)continue;
            for(int j=1; j<=sqrt(i); j++){
                dp[i] = min(dp[i], 1 + dp[i-(j*j)]);
            }
        }
        
        // for(int i=1; i<=n; i++)cout<<dp[i]<<" ";


        return dp[n];

    }
};