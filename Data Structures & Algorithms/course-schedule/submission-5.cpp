class Solution {
public:
    bool isCycle(int i, vector<vector<int>> &adj, vector<int> &visited){
        
        visited[i]=1;
        for(int j: adj[i]){
            if(visited[j]==1) return true;
            if(visited[j]==0 && isCycle(j, adj, visited)){
                return true;
            }
        }
        visited[i]=2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<n; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> visited(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            if(visited[i]==0 && isCycle(i, adj, visited)){
                return false;
            }
        }
        return true;
    }
};
