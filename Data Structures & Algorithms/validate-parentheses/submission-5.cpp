class Solution {
public:
    bool isValid(string s) {
        
        int n = s.size();
        if(n%2==1)
            return false;
        stack<int>st;

        for(int i=0; i<n; i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if((s[i]=='}' || s[i]==']' || s[i]==')') && st.empty()){
                    return false;
            }
            else if(s[i]==')' && st.top()=='('){
                st.pop();
            }
            else if(s[i]=='}' && st.top()=='{'){
                st.pop();
            }
            else if(s[i]==']' && st.top()=='['){
                st.pop();
            }
            else 
                return false;
        }
        if(!st.empty())
            return false;
        return true;
    }
};
