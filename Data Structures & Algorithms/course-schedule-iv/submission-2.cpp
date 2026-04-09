class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(auto x:prerequisites){
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        } 

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        unordered_map<int,unordered_set<int>> mp;
        while(q.size()){
            int node=q.front(); q.pop();
            
            for(auto x:adj[node]){
                mp[x].insert(node);
                if(mp.find(node)!=mp.end() && !mp[node].empty()){
                    for(auto y:mp[node])
                        mp[x].insert(y);
                }
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        vector<bool> ans;
        for(auto x:queries){
            if(mp[x[1]].count(x[0]))ans.push_back(true);
            else ans.push_back(false);
        }
        
        return ans;
    }
};