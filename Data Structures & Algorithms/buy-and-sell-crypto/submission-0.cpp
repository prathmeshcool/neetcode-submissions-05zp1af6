class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        int mx=prices[n-1],ans=0;
        for(int i=n-1; i>=0 ;i--){
            // cout<<i<<endl;
            int val = mx-prices[i];
            ans=max(ans,val);
            mx=max(mx,prices[i]);
            // cout<<mx<<endl;
        }
        return max(ans,0);
        
    }
};
