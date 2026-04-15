class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,false));

        int ans=0;
        for(int i=0;i<m;i++){
            int num1=0,unvis=0;
            for(int j=0;j<n;j++){
                int lasti,lastj;
                if(grid[i][j]){
                    num1++;
                    if(num1==2 && !visited[lasti][lastj]){
                        unvis++;
                        visited[lasti][lastj]=true;
                    }
                    if(num1>1 && !visited[i][j]){
                        unvis++;
                        visited[i][j]=true;
                    }
                    lasti=i,lastj=j;
                }
            }
            if(num1>1)
                ans+=unvis;
        }
        cout<<ans<<endl;
        for(int j=0;j<n;j++){
            int num1=0,unvis=0;
            for(int i=0;i<m;i++){
                int lasti,lastj;
                if(grid[i][j]){
                    num1++;
                    if(num1==2 && !visited[lasti][lastj]){
                        unvis++;
                        visited[lasti][lastj]=true;
                    }
                    if(num1>1 && !visited[i][j]){
                        unvis++;
                        visited[i][j]=true;
                    }
                    lasti=i,lastj=j;
                }
            }
            if(num1>1)
                ans+=unvis;
        }

        return ans;
    }
};