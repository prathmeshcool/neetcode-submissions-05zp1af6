class Solution {
public:
    
    vector<int> dp;

    int minCoins(vector<int> &coins, int amount){
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;

        if(dp[amount]!=-1)
            return dp[amount];
        
        int ans = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            
            int val =  minCoins(coins, amount-coins[i]);
            if(val!=INT_MAX)
                ans = min(ans, 1 + val);
        
        }
        
            return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        
        dp.resize(amount+1, -1);

        int val = minCoins(coins, amount);
        
        return val==INT_MAX?-1:val;
    }
};
