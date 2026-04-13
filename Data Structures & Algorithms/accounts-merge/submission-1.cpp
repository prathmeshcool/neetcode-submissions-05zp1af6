class Solution {
public:
    vector<int> par;
    vector<int> rank;

    void DSU(int n){    
        par.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }

    int find(int i){
        if(par[i]!=i)
            return par[i]=find(par[i]);

        return i;    
    }

    void Union(int i, int j){
        int iroot=find(i);
        int jroot=find(j);

        if(iroot==jroot)return;

        if(rank[iroot]>rank[jroot]){
            par[jroot]=iroot;
        }
        else if(rank[jroot]>rank[iroot]){
            par[iroot]=jroot;
        }
        else{
            par[iroot]=jroot;
            rank[jroot]++;
        }
    }


    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();

        unordered_map<string,int> mp1;
        unordered_map<int,string>mp2;
        unordered_map<string,string>mp3;
        
        int id=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<accounts[i].size();j++){
                if(j==0)continue;
                if(mp1.find(accounts[i][j])==mp1.end()){
                    mp1[accounts[i][j]]=id;
                    mp2[id]=accounts[i][j];
                    mp3[accounts[i][j]]=accounts[i][0];
                    id++;
                }
            }
        }

        DSU(id);
        for(int i=0;i<n;i++){
            for(int j=0;j<accounts[i].size()-1;j++){
                if(j==0)continue;
                Union(mp1[accounts[i][j]],mp1[accounts[i][j+1]]);
            }
        }

        unordered_map<int,unordered_set<int>> mp4;
        for(int i=0;i<n;i++){
            for(int j=0;j<accounts[i].size();j++){
                if(j==0)continue;   
                mp4[find(mp1[accounts[i][j]])].insert(mp1[accounts[i][j]]);
            }
        }        
        vector<vector<string>> ans;

        for(auto [x,y]:mp4){
            vector<string> v;
            v.push_back(mp3[mp2[x]]);
            for(auto z:y){
                v.push_back(mp2[z]);
            }
            ans.push_back(v);
        }

        return ans;
    }
};