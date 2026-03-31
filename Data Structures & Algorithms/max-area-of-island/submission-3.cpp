class Solution {
public:
    vector<vector<int>> directions={{0,1}, {1,0}, {-1,0}, {0,-1}};
    int ans = 0;
    void dfs(int i, int j, int cnt, vector<vector<bool>> &visited, vector<vector<int>> &grid){
        visited[i][j]=true;
        ans = max(ans, cnt);
        for(auto x: directions){
            int nc = i+x[0];
            int nr = j+x[1];

            if(nc<0 || nc>grid.size()-1 || nr<0 || nr>grid[0].size()-1 || !grid[nc][nr] || visited[nc][nr])continue;
            cnt++;
            dfs(nc, nr, cnt, visited, grid);
        }

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] && !visited[i][j]){
                    dfs(i, j, 1, visited, grid);
                }
            }
        }
        return ans;
    }
};
