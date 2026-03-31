class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for(int i =0; i<n; i++){
            if(tokens[i]=="+"){
                int c1 = st.top();
                st.pop();
                int c2 = st.top();
                st.pop();
                st.push(c1+c2);
            }
            else if(tokens[i]=="*"){
                int c1 = st.top();
                st.pop();
                int c2 = st.top();
                st.pop();
                st.push(c1*c2);        
            }
            else if(tokens[i]=="/"){
                int c1 = st.top();
                st.pop();
                int c2 = st.top();
                st.pop();
                st.push(c2/c1);
            }
            else if(tokens[i]=="-"){
                int c1 = st.top();
                st.pop();
                int c2 = st.top();
                st.pop();
                st.push(c2-c1);
            }
            else{
                int t = stoi(tokens[i]);
                st.push(t);
            }
        }
        return st.top();
    }
};
