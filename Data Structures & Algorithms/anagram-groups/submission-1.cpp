class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> mp;

        for(string str:strs){
            int cnt[26] = {0};
            for(char c:str){
                cnt[c-'a']++;
            }
            string key;
            for(int i=0; i<26; i++){
                key+= '#' + to_string(cnt[i]);
            }
            mp[key].push_back(str);
        }

        vector<vector<string>>v;
        for(auto x:mp){
            v.push_back(x.second);
        }
        return v;
    }
};
