class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int> &curr, int n, vector<int> &nums, vector<bool> &chk){

        if(curr.size()==n){
            res.push_back(curr);
            return;
        }

        for(int i=0; i<n; i++){
            if(chk[i]==true)continue;

            curr.push_back(nums[i]);
            chk[i]=true;

            backtrack(curr, n, nums, chk);

            curr.pop_back();
            chk[i]=false;
        }    
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr;
        vector<bool>chk(n,false);

        backtrack(curr, n, nums, chk);

        return res;
    }
};
