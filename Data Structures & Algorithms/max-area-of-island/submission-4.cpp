class Solution {
public:
    vector<vector<int>> directions={{0,1}, {1,0}, {-1,0}, {0,-1}};
    
    int dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &grid){
        visited[i][j]=true;
        int area = 1;
        for(auto x: directions){
            int nc = i+x[0];
            int nr = j+x[1];

            if(nc<0 || nc>grid.size()-1 || nr<0 || nr>grid[0].size()-1 || !grid[nc][nr] || visited[nc][nr])continue;                    
            area+=dfs(nc, nr, visited, grid);
        }

        return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] && !visited[i][j]){
                    ans = max(ans, dfs(i, j, visited, grid));
                }
            }
        }
        return ans;
    }
};
