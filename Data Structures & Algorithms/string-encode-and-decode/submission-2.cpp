class Solution {
public:

    string encode(vector<string>& strs) {
        int n=strs.size();
        string ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<strs[i].size();j++){
                ans.push_back(strs[i][j]);
            }
            ans.push_back(char(255));
        }
        return ans;
    }

    vector<string> decode(string s) {
        int n=s.size();

        vector<string>ans;
        string ns;
        for(int i=0;i<n;i++){
            if(s[i]==char(255)){
                ans.push_back(ns);
                ns.clear();
                continue;
            }
            ns.push_back(s[i]);
        }
        return ans;
    }
};
