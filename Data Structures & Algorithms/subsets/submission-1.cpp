class Solution {
public:
    vector<vector<int>> ans;

    void Backtrack(int index, vector<int> &curr, int n, vector<int>&nums){

        ans.push_back(curr);
        
        for(int i=index; i<n; i++){
            curr.push_back(nums[i]);
            Backtrack(i+1, curr, n, nums);
            curr.pop_back();
        }        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>curr;
        Backtrack(0, curr, n, nums);
        return ans;    
    }
};
