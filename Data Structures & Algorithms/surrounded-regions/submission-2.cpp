class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    void dfs(int i, int j, vector<vector<char>> &board){
        board[i][j]='C';

        for(auto x: directions){
            int nc = i+x[0];
            int nr = j+x[1];

            if(nc<0 || nc>board.size()-1 || nr<0 || nr>board[0].size()-1)continue;
            if(board[nc][nr]=='O')
                dfs(nc, nr, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        for(int i=0; i<n; i++){
            if(board[0][i]=='O'){
                dfs(0, i, board);
            }
            if(board[m-1][i]=='O'){
                dfs(m-1, i, board);
            }
        }

        for(int i=0; i<m; i++){
            if(board[i][0]=='O'){
                dfs(i, 0, board);
            }
            if(board[i][n-1]=='O'){
                dfs(i, n-1, board);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='C')
                    board[i][j]='O';
            }
        }

    }
};
