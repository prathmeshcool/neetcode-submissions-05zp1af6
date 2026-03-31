class Solution {
public:

    void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &grid){

        int m = grid.size(), n = grid[0].size();
                
        visited[i][j]=true;
        if(i!=m-1 && !visited[i+1][j] && grid[i+1][j]=='1'){
            dfs(i+1,j, visited, grid);
        }
        if(j!=n-1 && !visited[i][j+1] && grid[i][j+1]=='1'){
            dfs(i, j+1, visited, grid);
        }
        if(i!=0 && !visited[i-1][j] && grid[i-1][j]=='1'){
            dfs(i-1, j, visited, grid);
        }
        if(j!=0 && !visited[i][j-1] && grid[i][j-1]=='1'){
            dfs(i, j-1, visited, grid);
        }


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
