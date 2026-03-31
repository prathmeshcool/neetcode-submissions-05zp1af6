class Solution {
public:
    vector<vector<string>> res;

    
    bool isPalindrome(string s){
        int n = s.size();
    
        
        for(int i=0; i<n/2; i++){
            if(s[i]!=s[n-i-1])
                return false;
        }
        return true;
    }
    
    void backtrack(int index, vector<string> &v, int n, string s){
        if(index==n){
            res.push_back(v);
            return;
        }
        string curr;
        for(int i=index; i<n; i++){
            curr.push_back(s[i]);
            
            if(!isPalindrome(curr))continue;
            v.push_back(curr);
            
            backtrack(i+1, v, n, s);

            v.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        
        vector<string> v;
        backtrack(0, v, n, s);

        return res;
    }
};
