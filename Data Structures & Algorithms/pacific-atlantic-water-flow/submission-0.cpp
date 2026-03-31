class Solution {
public:

    void dfs(int i, int j, int lastValue, vector<vector<bool>> &visited, vector<vector<int>> &heights){
        if(i<0 || j<0 || i>heights.size()-1 || j>heights[0].size()-1 || visited[i][j] || heights[i][j]<lastValue){
            return;
        }
        visited[i][j]=true;
        dfs(i+1, j, heights[i][j], visited, heights);
        dfs(i-1, j, heights[i][j], visited, heights);
        dfs(i, j+1, heights[i][j], visited, heights);
        dfs(i, j-1, heights[i][j], visited, heights);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<bool>> visited1(m, vector<bool>(n, false));
   
        for(int i=0; i<m; i++){
            if(!visited1[i][0]){
                dfs(i, 0, 0, visited1, heights);
            }
        }
        for(int i=0; i<n; i++){
            if(!visited1[0][i]){
                dfs(0, i, 0, visited1, heights);
            }
        }

        vector<vector<bool>> visited2(m, vector<bool>(n, false));
    
        for(int i=0; i<m; i++){
            if(!visited2[i][n-1]){
                dfs(i, n-1, 0, visited2, heights);
            }
        }
        for(int i=0; i<n; i++){
            if(!visited2[m-1][i]){
                dfs(m-1, i, 0, visited2, heights);
            }
        }

        vector<vector<int>> ans;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visited1[i][j] && visited2[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }

};
