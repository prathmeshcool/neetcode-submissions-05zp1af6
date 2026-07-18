class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size(), m = secondList.size();

        int i = 0, j = 0;

        vector<vector<int>> ans;
        while(i!=n && j!=m){
            int a = firstList[i][0], b = firstList[i][1];
            int c = secondList[j][0], d = secondList[j][1];

            // cout<<a<<" "<<b<<"   "<<c<<" "<<d<<endl;
            if(a<=d && c<=b){
                int mx = max(a,c);
                int mn = min(b,d);
                ans.push_back({mx,mn});
            }

            if(b<=d)i++;
            else j++;
        }

        return ans;
    }
};