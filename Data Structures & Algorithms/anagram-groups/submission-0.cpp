class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> s = strs;

        unordered_map<string,vector<string>>mp;
        for(int i=0; i<s.size();i++){
            sort(s[i].begin(),s[i].end());
            mp[s[i]].push_back(strs[i]);
        }
        
        vector<vector<string>>ans;
        
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
