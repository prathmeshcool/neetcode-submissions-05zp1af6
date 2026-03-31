class Solution {
public:
    bool hasCycle(int i, vector<vector<int>> &adj, vector<int> &visited, vector<int> &ans){
        if(visited[i]==2)
            return false;
        if(visited[i]==1)
            return true;
        // cout<<i<<endl;

        visited[i]=1;
        for(auto x: adj[i]){
            if(hasCycle(x, adj, visited, ans)){
                return true;
            }
        }
        visited[i]=2;
        ans.push_back(i);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);

        for(int i=0; i<n; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> visited(numCourses);
        vector<int> ans;
        for(int i=0; i<numCourses; i++){
            if(visited[i]==2)continue;
            if(hasCycle(i, adj, visited, ans)){
                return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
