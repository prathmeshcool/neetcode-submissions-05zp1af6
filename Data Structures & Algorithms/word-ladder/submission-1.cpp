class Solution {
public:
    int ans = INT_MAX;
    bool chk = false;
   
    void dfs(string curr, string endWord, vector<bool> &visited, vector<string> &wordList, int cnt, vector<string> &res){
        if(curr==endWord){
            // for(auto x: res){
            //     cout<<x<<" ";
            // }
            // cout<<endl;
            chk = true;
            ans = min(ans, cnt);
            return;
        }
        for(int i=0; i<wordList.size(); i++){
            if(!visited[i]){
                int diff = 0;
                for(int j=0; j<curr.size(); j++){
                    if(curr[j]!=wordList[i][j])diff++;
                    if(diff>1)break;
                }
                if(diff==1){
                    visited[i]=true;
                    cnt++;
                    // res.push_back(curr);
                    dfs(wordList[i], endWord, visited, wordList, cnt, res);
                    // res.pop_back();
                    cnt--;
                    visited[i]=false;
                }
            }
        }
    }


    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<bool> visited(n, false);
         vector<string> res;
        dfs(beginWord, endWord, visited, wordList, 0, res);

        if(chk)
            return ans+1;
        return 0;

    }
};
