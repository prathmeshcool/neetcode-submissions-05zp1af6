class Solution {
public:
    vector<vector<int>> ans;
    void Backtrack(int index, vector<int> &curr, int n, vector<int>&nums){
        
        if(index==n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        Backtrack(index+1, curr, n, nums);
        curr.pop_back();

        Backtrack(index+1, curr, n, nums);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>curr;
        Backtrack(0, curr, n, nums);
        return ans;    
    }
};
