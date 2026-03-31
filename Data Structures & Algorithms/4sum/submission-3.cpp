class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int k = j+1, l=n-1;
                long long sum=(long long)(nums[i]+nums[j]);
                long long need=(long long)(target-(sum));
                int id1=-1,id2=-1;
                while(k<l){
                    long long curr=(long long)(nums[k]+nums[l]);
                    if(curr==need){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        int val1 = nums[l], val2=nums[k];
                        while(nums[l]==val1)l--;
                        while(nums[k]==val2)k++;
                    }
                    else if(curr>need)l--;
                    else k++;      
                }
            }
        }

        return ans;
    }
};