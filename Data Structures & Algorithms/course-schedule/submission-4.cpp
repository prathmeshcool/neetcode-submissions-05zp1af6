class Solution {
public:
    bool ans = true;
   void hasCycle(int i, vector<vector<int>> &adj, vector<int> &visited){
        if(visited[i]==2){
            return;
        }
        if(visited[i]==1){
            ans = false;
            return;
        }
        visited[i]=1;
        for(auto x:adj[i]){
            hasCycle(x, adj, visited);
        }
        visited[i]=2;
   }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0){
            return true;
        }
        int n = prerequisites.size();
         vector<vector<int>> adj(numCourses);

     
         for(int i=0; i<n; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
         }

        vector<int> visited(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            hasCycle(i, adj, visited);  
            if(!ans)
                return false;
        }
        return true;
    }
};
