class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(int i=0; i<n; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }   
        queue<int> q;

        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> ans;
        while(q.size()){
            int i = q.front();
            q.pop();
            ans.push_back(i);
            for(int x:adj[i]){
                indegree[x]--;
                if(!indegree[x]){
                    q.push(x);
                }
            }
        }

        if(ans.size()==numCourses){
            return ans;
        }
        
        return {};
            
        
    }
};
