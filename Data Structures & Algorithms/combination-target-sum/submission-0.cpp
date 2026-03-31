class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int index, vector<int>& curr, int n, vector<int> &nums, int sum, int target){
        if(sum>target){
            return;
        }
        if(sum == target){
            res.push_back(curr);
            return;
        }

        for(int i=index; i<n; i++){
            if(i>index && nums[i]==nums[i-1])continue;

            curr.push_back(nums[i]);
            sum+=nums[i];

            backtrack(i,curr,n,nums,sum,target);

            curr.pop_back();
            sum-=nums[i];
        }

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int> curr;
        int sum = 0;
        backtrack(0, curr, n, nums, sum, target);

        return res;


    }
};
