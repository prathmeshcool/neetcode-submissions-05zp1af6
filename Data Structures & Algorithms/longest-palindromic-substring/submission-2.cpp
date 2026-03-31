class Solution {
public:
    bool fun(int i, int j, string s, vector<vector<int>>&dp){
        if(i==j)return 1;
        if(j-i==1){
            if(s[i]==s[j])return 1;
            else return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]){
            return dp[i][j]=fun(i+1, j-1, s, dp);
        }

        return dp[i][j]=0;
        
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==1)
            return s;
        if(n==2){
            if(s[0]==s[1])return s;
            else{
             return s.substr(0,1);
            }
                
        }
        vector<vector<int>> dp(n, vector<int>(n,-1));
        fun(0, n-1, s, dp);

        int mx=1;
        string ans;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j]==-1){
                    dp[i][j]=fun(i,j,s,dp);
                }
                if(dp[i][j]==1 && j-i+1>mx){
                    mx = max(mx, j-i+1);
                    ans = s.substr(i,j-i+1);
                }
            }
        }

        return ans;

    }
};
