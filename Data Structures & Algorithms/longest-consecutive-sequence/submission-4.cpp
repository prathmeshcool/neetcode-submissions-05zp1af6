class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> s(nums.begin(),nums.end());
       
       int ans= 0;
       for(int x:s){
            
            if(!s.count(x-1)){
                int l = x, cnt=0;
                while(s.count(l)){
                    l++;
                    cnt++;
                    ans=max(ans,cnt);
                }
            }
       }
       return ans;
    }
};
