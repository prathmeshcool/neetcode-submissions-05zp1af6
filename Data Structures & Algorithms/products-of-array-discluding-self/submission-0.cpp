class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size()), right(nums.size());

        int n = nums.size();
        left[0]=nums[0];
        right[nums.size()-1]=nums[nums.size()-1];
        for(int i=1; i<nums.size(); i++){
            left[i]=left[i-1]*nums[i];
            cout<<left[i]<<endl;
        }
        cout<<endl;
        for(int i=nums.size()-2; i >=0 ; i--){
            right[i]=nums[i]*right[i+1];
            
            cout<<right[i]<<endl;
        }
        vector<int> ans(nums.size());

        ans[0]=right[1];
        ans[nums.size()-1]=left[nums.size()-2];

        for(int i=1;i<nums.size()-1;i++){
            ans[i]=left[i-1]*right[i+1];
        }
        return ans;
    }
};
