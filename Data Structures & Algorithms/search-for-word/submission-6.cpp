class Solution {
public:
    vector<vector<int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
    bool fun(int i, int j, int id, string &word, vector<vector<bool>>&visited, vector<vector<char>>& board){
        if(id == word.size()-1){      
            return true;
        }
        visited[i][j]=true;
        for(auto x:directions){
            int nc=i+x[0];
            int nr=j+x[1];
            if(nc<0 || nr<0 || nc>=board.size() || nr>=board[0].size() || visited[nc][nr] || board[nc][nr]!=word[id+1])continue;
            if(fun(nc,nr,id+1,word,visited,board))
                return true;
        }
        visited[i][j]=false;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!=word[0])continue;;
                if(fun(i,j,0,word,visited,board))
                    return true;
            }
        }
        return false;
    }
};
