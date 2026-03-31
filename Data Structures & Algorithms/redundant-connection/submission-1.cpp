class Solution {
public:
    vector<int> parent, rank;

    void DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }

    int find(int x){
        int root = parent[x];

        if(parent[root]!=root){
            return parent[x]=find(root);
        }

        return root;
        
    }
    void unionSet(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);

        if(xRoot==yRoot)
            return;

        if(rank[xRoot]<rank[yRoot]){
            parent[xRoot]=yRoot;
        }
        else if(rank[yRoot]<rank[xRoot]){
            parent[yRoot]=xRoot;
        }
        else{
            parent[yRoot]=xRoot;
            rank[xRoot]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DSU(n+1);
        int ansX=-1, ansY=-1;

        vector<int> ans;
        int cnt = 0;
        for(int i=0; i<n; i++){
            int x=edges[i][0], y=edges[i][1];
            if(find(x)==find(y)){
                ans.push_back(x);
                ans.push_back(y);
                return ans;
            }
            else{
                unionSet(x,y);
            }
        }


        return ans;
            

    }
};
