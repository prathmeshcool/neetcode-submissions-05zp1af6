class Solution {
public:
    int ans = 0;
    bool dfs(int i, vector<vector<int>> &adj, vector<int> &visited, vector<bool>& hasApple){
        
        bool chk = false;

        for(auto x:adj[i]){
            if(!visited[x]){
                visited[x] = 1;
                if(dfs(x, adj, visited, hasApple)){
                    chk = true;
                    ans+=2;
                }
            }
        }
        
        if(hasApple[i])chk = true;

        return chk;

    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);

        for(auto d:edges){
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }
        vector<int> visited(n, 0);
        visited[0] = 1;
        dfs(0, adj, visited, hasApple);

        return ans;
    }
};