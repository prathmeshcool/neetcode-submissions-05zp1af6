class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,0));

        int cnt=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]){
                    if(j-i<=1){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
                cnt+=dp[i][j];
            }
        }
        return cnt;
    } 
};
