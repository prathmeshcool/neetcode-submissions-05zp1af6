class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n<=2){
            int mx = *max_element(nums.begin(),nums.end());
            return mx;
        }


        int dp1[n], dp2[n+1];

        dp1[0]=nums[0], dp1[1] = max(nums[0], nums[1]);
        
        for(int i=2; i<n-1; i++){
            dp1[i]=max(dp1[i-1], dp1[i-2]+nums[i]);
        }

        dp2[1]=nums[1]; dp2[2]=max(nums[1],nums[2]);

        for(int i=3; i<n; i++){
            dp2[i]=max(dp2[i-1], dp2[i-2]+nums[i]);
        }

        return max(dp1[n-2], dp2[n-1]);
    }
};
