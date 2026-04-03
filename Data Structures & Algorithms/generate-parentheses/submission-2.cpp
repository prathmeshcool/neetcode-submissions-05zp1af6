class Solution {
public:
    vector<string> ans;
    
    void fun(int id,int len,int open,int close,string curr){
        if(id==len){
            ans.push_back(curr);
            return;
        }
        if(open<len/2){
            curr.push_back('(');
            fun(id+1, len, open+1, close, curr);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            fun(id+1, len, open, close+1, curr);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int len = n*2;
        fun(0,len,0,0,"");
        return ans;
    }
};
