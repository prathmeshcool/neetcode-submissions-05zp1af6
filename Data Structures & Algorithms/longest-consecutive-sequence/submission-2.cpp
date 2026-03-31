class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        priority_queue<int, vector<int>,greater<int>> pq;

        unordered_set<int> s;

        int n= nums.size();
        if(n==0)
            return 0;
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }
        for(auto x:s){
            pq.push(x);
        }
        int last = pq.top();
        pq.pop();

        int cnt=1,mx=INT_MIN;
        while(pq.size()){
            int cur = pq.top();
            cout<<cur<<" "<<last<<endl;
            if(cur-1==last){
                cnt++;
                mx=max(mx,cnt);
            }
            else{
                cnt=1;
            }
            pq.pop();
            last=cur;
        }

        return max(mx,cnt);
    }
};
