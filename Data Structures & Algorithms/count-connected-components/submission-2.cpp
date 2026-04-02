class Solution {
public:
    vector<int> parent;
    vector<int>rank;

    void DSU(int n){
        parent.resize(n);
        rank.resize(n,1);

        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    int find(int i){
        int root = parent[i];

        if(parent[root]!=root){
            return parent[i]=find(root);
        }
        return root;
    }

    void Union(int i, int j){
        int iroot=find(i);
        int jroot=find(j);

        if(rank[iroot]>rank[jroot]){
            parent[jroot]=iroot;
        }
        else if(rank[jroot]>rank[iroot]){
            parent[iroot]=jroot;
        }
        else{
            parent[iroot]=jroot;
            rank[jroot]++;
        }
    }


    int countComponents(int n, vector<vector<int>>& edges) {
        
        DSU(n);
        for(auto &x:edges){
            Union(x[0],x[1]);
        }

        unordered_set<int> s;

        for(int i=0; i<n; i++){
            int root = find(i);
            s.insert(root);
        }


        return s.size();

    }
};
