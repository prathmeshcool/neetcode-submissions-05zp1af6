class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int n = piles.size();
       int mx = *max_element(piles.begin(),piles.end());

       int l =1, r=mx, ans=-1;

       while(l<=r){
            int mid = l+(r-l)/2;
            int sum = 0;
            for(int i=0;i<n;i++){
                sum+=(piles[i]+mid-1)/mid;
            }
            if(sum<=h){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
       }
       return ans;
    }
};
