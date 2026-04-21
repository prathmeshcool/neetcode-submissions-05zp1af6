class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int l=0,r=n-k;

        while(l<r){
            int mid=l+(r-l)/2;
            if(abs(x-arr[mid])>abs(x-arr[mid+k]))
                l=mid+1;
            else
                r=mid;
        }
        vector<int> ans;
        for(int i=l;i<l+k;i++)
            ans.push_back(arr[i]);

        return ans;
    }
};