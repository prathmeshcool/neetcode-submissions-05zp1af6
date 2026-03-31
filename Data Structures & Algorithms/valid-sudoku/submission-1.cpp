class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            map<char,int> mp1,mp2;
            for(int j=0;j<9; j++){        
                if(board[i][j]!='.'){
                    if(mp1.count(board[i][j]))
                        return false;
                    mp1[board[i][j]]++;
                }   

                if(board[j][i]!='.'){
                    if(mp2.count(board[j][i]))
                        return false;
                    mp2[board[j][i]]++;
                }           
            }
        }
            
        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                map<char,int> mp;
                for(int k=0;k<3;k++){
                    for(int l=0;l<3; l++){
                        if(board[i+k][j+l]=='.')
                            continue;      
                        if(mp.count(board[i+k][j+l]))
                            return false;
                        mp[board[i+k][j+l]]++;
                    }
                }
            }
        }
        return true;
    }
};
