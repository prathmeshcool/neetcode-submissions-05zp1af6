class Solution {
public:
    int INF = INT_MAX;
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        
        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!grid[i][j]){
                    q.push({i, j});
                }
            }
        }
       
        while(q.size()){
            int sz = q.size();

            for(int i=0; i<sz; i++){
                pair<int,int> p = q.front();
                q.pop();

                int a = p.first, b = p.second;
                for(auto x:directions){
                    int nc = a + x[0];
                    int nr = b + x[1];

                    if(nc<0 || nr<0 || nc>=n || nr>=m || grid[nc][nr]!=INF)continue;
                    grid[nc][nr]=grid[a][b]+1;
                    q.push({nc,nr});
                }
            }
        }

    }
};
