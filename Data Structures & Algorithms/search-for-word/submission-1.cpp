class Solution {
public:
    bool ans=false;
    vector<vector<int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
    void fun(int i, int j, int id, string &word, vector<vector<bool>>&visited, vector<vector<char>>& board){

        if(ans)
            return;

        if(id==word.size()-1){
            ans=true;
            return;
        }
        visited[i][j]=true;
        for(auto x:directions){
            int nc=i+x[0];
            int nr=j+x[1];
            if(nc<0 || nr<0 || nc>=board.size() || nr>=board[0].size() || visited[nc][nr] || board[nc][nr]!=word[id+1])continue;
            fun(nc,nr,id+1,word,visited,board);
        }
        visited[i][j]=false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!=word[0])continue;;
                fun(i,j,0,word,visited,board);
            }
        }


        return ans;
    }
};
