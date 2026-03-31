class Solution {
public:
    bool chk = true;
    void dfs(int i, int par, vector<bool>&visited, vector<vector<int>> &adj){
        visited[i]=true;

        for(auto x:adj[i]){
            if(x==par)continue;
            if(visited[x]){
                chk = false;
                return;
            }
            dfs(x, i, visited, adj);
        }

    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        
        for(auto v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        dfs(0, -1, visited, adj);

        for(int i=0; i<n; i++){
            if(!visited[i])
                return false;
        }

        return chk;
    }
};
