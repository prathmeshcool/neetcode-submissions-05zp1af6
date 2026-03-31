class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l=0, mx= 0, ans=0;
        
        unordered_map<char, int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            mx = max(mx,mp[s[i]]);
            while((i-l+1)-mx>k){                    
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};
