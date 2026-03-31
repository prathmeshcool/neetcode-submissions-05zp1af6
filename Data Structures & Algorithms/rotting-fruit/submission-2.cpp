class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int,int>> q;
        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2)
                    q.push({i, j});
                else if(grid[i][j]==1)
                    cnt++;
            }
        }
        if(cnt==0)
            return 0;


        int ans = 0;

        while (q.size()){
            int sz = q.size();
            ans++;
            for(int i=0; i<sz; i++){
                pair<int,int> p = q.front();
                q.pop();
                for(auto x:directions){
                    int nc = x[0]+p.first;
                    int nr = x[1]+p.second;
                    if(nc<0 || nc>m-1 || nr<0 || nr>n-1 || grid[nc][nr]!=1)continue;
                    q.push({nc, nr});
                    cnt--;
                    grid[nc][nr]=2;
                }
            }
        }
        if(cnt==0){
            return ans-1;
        }

        return -1;
         
    }
};
