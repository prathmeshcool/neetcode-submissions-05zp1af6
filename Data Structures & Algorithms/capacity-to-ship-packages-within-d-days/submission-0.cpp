class Solution {
public:
    bool function(int wt, vector<int>& weights, int days){
        
        int n = weights.size();
        int sum=0, cnt = 0;
        for(int i=0; i<n; i++){
            if(sum+weights[i]>wt){
                cnt++;
                sum = weights[i];
                continue;
            }
            sum+=weights[i];
        }
        cnt+=(sum>0);
        cout<<wt<<" "<<cnt<<endl;
        if(cnt<=days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = accumulate(weights.begin(), weights.end(),0);
        int mx = *max_element(weights.begin(), weights.end());
        int l=mx, r=sum;

        while(l<r){
            int mid=l+(r-l)/2;
            if(function(mid, weights, days)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};