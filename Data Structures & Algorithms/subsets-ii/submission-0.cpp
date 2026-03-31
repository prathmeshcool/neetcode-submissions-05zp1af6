class Solution {
public:
    vector<vector<int>> res;
    
    void backtrack(int index, vector<int> &curr, int n, vector<int> &nums){

            res.push_back(curr);

            for(int i=index; i<n; i++){
                if(i>index && nums[i]==nums[i-1])
                        continue;
                curr.push_back(nums[i]);
                backtrack(i+1, curr, n, nums);
                curr.pop_back();
            }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>curr;
        backtrack(0, curr, n, nums);
        return res;
    }
};
