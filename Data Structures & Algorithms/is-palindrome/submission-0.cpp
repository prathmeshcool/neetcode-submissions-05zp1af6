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
        string e = d;
        reverse(d.begin(),d.end());
        return e==d;
    }
};
