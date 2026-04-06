class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n=deadends.size();
        unordered_set<string> visited;
        
        for(int i=0;i<n;i++){
            visited.insert(deadends[i]);
        }
        if(visited.count("0000"))
            return -1;

        queue<string> q;      
        q.push("0000");
        visited.insert("0000");
        int cnt=-1;
        while(q.size()){

            int sz=q.size();
            // cout<<sz<<endl;
            cnt++;
            for(int i=0; i<sz; i++){
                
                string s=q.front(); q.pop();
                
                if(s==target)
                    return cnt;                
                for(int j=0;j<4;j++){
                    string ns=s;
                    if(ns[j]!='9'){
                        ns[j]+=(1);
                    }
                    else{
                        ns[j]='0';
                    }
                    if(!visited.count(ns)){
                        visited.insert(ns);
                        q.push(ns);
                    }
                }
                for(int j=0;j<4;j++){
                    string ns=s;
                    if(ns[j]!='0'){
                        ns[j]-=(1);
                    }
                    else{
                        ns[j]='9';
                    }
                    if(!visited.count(ns)){
                        visited.insert(ns);
                        q.push(ns);
                    }
                }
                
            }
        }
        return -1;
    }
};