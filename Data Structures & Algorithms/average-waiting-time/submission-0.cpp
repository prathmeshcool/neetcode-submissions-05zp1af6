class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double n = customers.size();
        double t = 0;

        double sum = 0;
        for(auto x:customers){
            t = max(t, (double)x[0]);
            t+=x[1];
            sum += (t-x[0]);
        }

        return (sum/n); 

    }
};