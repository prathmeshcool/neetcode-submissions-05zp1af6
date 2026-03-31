class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l=0, r= m-1;

        if(target>matrix[m-1][n-1] || target<matrix[0][0])
            return false;

        int row = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            // cout<<mid<<endl;
            if(matrix[mid][0]<=target){
                row = mid ;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
      
        // cout<<row<<endl;          

        l = 0, r=n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(matrix[row][mid]==target){
                return true;
            }
            else if(matrix[row][mid]>target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return false;
    }
};
