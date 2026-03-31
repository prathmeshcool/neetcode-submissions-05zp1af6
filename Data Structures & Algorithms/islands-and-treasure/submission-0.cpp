class Solution {
public:
    int INF = INT_MAX;
    vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    int bfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &grid){

        queue<pair<int, int>> q;
        q.push({i, j});
        int cnt = 0;
        while(q.size()){

            int sz = q.size();
            cnt++;
            for(int j=0; j<sz; j++){
                pair<int, int> p = q.front();
                q.pop();                 
                int x = p.first, y = p.second;
                visited[x][y]=true;
     
                for(auto x:directions){
                    int nc = p.first+x[0];
                    int nr = p.second+x[1];
                    if(nc<0 || nr<0 || nc>grid.size()-1 || nr>grid[0].size()-1 || visited[nc][nr] || grid[nc][nr]==-1)continue;
                    if(!grid[nc][nr])
                        return cnt;
                    q.push({nc, nr});
                }         
            } 
        }
        return 2147483647;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
       
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2147483647){
                    vector<vector<bool>> visited(m, vector<bool> (n, false));
                    grid[i][j]=bfs(i, j, visited, grid);
                }
            }
        }    
    }
};
