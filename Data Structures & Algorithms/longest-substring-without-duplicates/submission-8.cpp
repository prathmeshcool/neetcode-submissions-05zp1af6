class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0, ans=0;
        unordered_map<char,int> mp;
       
       for(int i=0;i<n;i++){
            if(mp.count(s[i])){
                l=max(l,mp[s[i]]+1);
            }
            mp[s[i]]=i;
            ans=max(ans, i-l+1);
       }
       return ans;
    }
};
