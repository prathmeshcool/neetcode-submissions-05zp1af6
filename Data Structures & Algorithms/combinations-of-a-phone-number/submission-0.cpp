class Solution {
public:
    vector<string> res;

    void backtrack(int index, string curr, int n, string digits, unordered_map<char, string> &mp){
        if(index==n){
            res.push_back(curr);
            return;
        }
        string s = mp[digits[index]];
        for(int i=0; i<s.size(); i++){
            curr.push_back(s[i]);

            backtrack(index+1, curr, n, digits, mp);

            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        unordered_map<char,string> mp;
        if(n==0)
            return {};
        //mapping numbers to their possible characters
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";

        string curr;
        backtrack(0, curr, n, digits, mp);
        
        return res;

    }
};
