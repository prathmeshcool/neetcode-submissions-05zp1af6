class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l =0, r=n-1;

        if(nums.size()==1)
            return nums[0];
        else if(nums.size()==2){
            return min(nums[l],nums[r]);
        }
        
        if(nums[l]<nums[r])
            return nums[l];


        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid]<=nums[r]){
                r=mid;
            }
            else{
                l=mid+1;
            }    
        }
        return nums[l];
    }
};
