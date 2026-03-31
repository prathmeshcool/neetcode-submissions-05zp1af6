class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int mx=0;
        string ans;
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                    if(i==j)dp[i][j]=1;
                    else if(j-i==1){
                        if(s[i]==s[j])dp[i][j]=1;
                        else dp[i][j]=0;
                    }
                    else{
                        if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
            
                        else dp[i][j]=0;
                    }
                    if(dp[i][j]==1 && j-i+1>mx){
                        mx=j-i+1;
                        ans = s.substr(i,j-i+1);
                    }
            }        
        }

        return ans;
    }
    
};
