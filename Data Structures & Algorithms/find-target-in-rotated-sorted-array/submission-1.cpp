class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0, r=n-1;

        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid]<=nums[r]){
                r=mid;
            }
            else{
                l = mid+1;
            }
        }
        int start = l;
        if(target>nums[n-1]){
            l=0, r=start-1;
        }
        else{
            r=n-1;
        }
        cout<<l<<" "<<r<<endl;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;

    }
};
