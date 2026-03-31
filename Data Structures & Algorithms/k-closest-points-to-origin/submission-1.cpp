class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<double,double>,vector<pair<double,double>>, greater<pair<double,double>>> pq;

        for(int i=0; i<n; i++){
            double x = points[i][0];
            double y = points[i][1];
            double sum = x*x + y*y;
            sum = (double)sqrt(sum);
            // cout<<sum<<endl;
            pq.push({sum,i});
        }
        vector<vector<int>> ans;
        while(k--){
            pair<double,double> p = pq.top();
            pq.pop();
            ans.push_back(points[p.second]);
        }

        return ans;
    }
};
