class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        if(k<=1)return 0;


        int mul = 1;
        int l = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            mul*= nums[i];
            while(l<=i && mul>=k){
                mul/=nums[l];
                l++;
            }
            ans+= i - l + 1;
        }

        return ans;
    }
};