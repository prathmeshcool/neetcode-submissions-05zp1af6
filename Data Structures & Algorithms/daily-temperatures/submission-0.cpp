class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        int n = temperatures.size();
        vector<int> result(n, 0);
        st.push({temperatures[0],0});
        for(int i=1; i<n;i++){            
                while(!st.empty() && st.top().first < temperatures[i]){
                    pair<int,int> p = st.top();
                    result[p.second]=i-p.second;                    
                    st.pop();
                }
                st.push({temperatures[i],i});

        }
        return result;
    }
};
