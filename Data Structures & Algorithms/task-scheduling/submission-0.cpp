class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz = tasks.size();
        unordered_map<char,int> mp;
        for(int i=0; i<sz; i++){
            mp[tasks[i]]++;
        }

        priority_queue<int> pq;
        for(auto x: mp){
            pq.push(x.second);
        }
        int mx = pq.top();
        int cnt = 0;
        while(pq.size()){
            if(pq.top()!=mx)
                break;
            cnt++;
            pq.pop();
        }
        int ans = (mx-1)*(n+1)+cnt;

        return max(ans, sz);
    }
};
