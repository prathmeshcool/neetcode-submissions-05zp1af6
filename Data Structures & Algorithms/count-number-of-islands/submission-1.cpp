class Solution {
public:

    void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &grid){

        if(i<0 || i>grid.size()-1 || j<0 || j>grid[0].size()-1 || visited[i][j] || grid[i][j]=='0'){
            return;
        }
        visited[i][j]=true;
        dfs(i+1, j, visited, grid);
        dfs(i-1, j, visited, grid);
        dfs(i, j+1, visited, grid);
        dfs(i, j-1, visited, grid);

    }


    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    cnt++;
                    dfs(i, j, visited, grid);
                }
            }
        }
        
        return cnt;
    }
};
