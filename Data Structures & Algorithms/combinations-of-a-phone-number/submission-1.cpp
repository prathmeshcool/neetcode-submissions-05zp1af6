class Solution {
public:
    vector<string> res;

    void backtrack(int index, string curr, int n, string digits, vector<string> &v){
        if(index==n){
            res.push_back(curr);
            return;
        }
        string s = v[digits[index]-'0'];
        for(int i=0; i<s.size(); i++){
            curr.push_back(s[i]);

            backtrack(index+1, curr, n, digits, v);

            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        if(n==0){
            return {};
        }
        string curr;
        backtrack(0, curr, n, digits, v);
        
        return res;

    }
};
