class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();

        string d;
        for(int i =0;i<n ;i++){
            if(isalnum(s[i])){
                d.push_back(tolower(s[i]));
            }
        }
        return d==string(d.rbegin(),d.rend());
    }
};
