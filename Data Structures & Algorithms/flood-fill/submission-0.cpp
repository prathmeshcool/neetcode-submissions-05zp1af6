class Solution {
public:
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int i, int j, int curr, int color, vector<vector<int>> &image){

        for(auto d:directions){
            int nr = i + d[0];
            int nc = j + d[1]; 
            if(nr<0 || nc<0 || nr>=image.size() || nc>=image[0].size() || image[nr][nc]!=curr)continue;
            
            image[nr][nc] = color;
            dfs(nr, nc, curr, color, image);
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc]==color)return image;

        int curr = image[sr][sc];
        image[sr][sc] = color;

        dfs(sr, sc, curr, color, image);

        return image;


    }
};