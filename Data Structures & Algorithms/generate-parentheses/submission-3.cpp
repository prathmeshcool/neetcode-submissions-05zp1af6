class Solution {
public:
    vector<string> ans;
    
    void fun(int id,int len,int sum,string curr){
        if(id==len && sum==0){
            ans.push_back(curr);
            return;
        }
        if(sum<0 || id==len){
            return;
        }
        if(sum+1<=len/2){
            curr.push_back('(');
            fun(id+1, len, sum+1, curr);
            curr.pop_back();
        }
        if(sum-1>=0){
            curr.push_back(')');
            fun(id+1, len, sum-1, curr);
            curr.pop_back();
        }
        
        // return;
    }
    vector<string> generateParenthesis(int n) {
        int len = n*2;
        fun(0,len,0,"");
        return ans;
    }
};
