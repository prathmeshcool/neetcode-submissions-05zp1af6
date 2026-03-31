class Solution {
public:
    vector<vector<int>> res;

    void backtrack(int index, vector<int> &curr, int n, vector<int> &candidates, int sum, int target){
        
        if(sum==target){
            res.push_back(curr);
            return;
        }
        for(int i=index; i<n; i++){
            if(i>index && candidates[i]==candidates[i-1])continue;
            if(sum+candidates[i]>target)break;

            curr.push_back(candidates[i]);
            sum+=candidates[i];

            backtrack(i+1, curr, n, candidates, sum, target);

            curr.pop_back();
            sum-=candidates[i];
        }
    
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       int n = candidates.size();
       sort(candidates.begin(),candidates.end());
       vector<int> curr;
       int sum = 0;
       backtrack(0, curr, n, candidates, sum, target);
       
       return res;
    }
};
