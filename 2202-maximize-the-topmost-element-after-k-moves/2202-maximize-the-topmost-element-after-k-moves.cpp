class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n==1) {
            if(k%2==1) return -1;
            return nums[0];
        }
        int maxi = -1;
        
        for(int i=0; i<min(n,k-1); i++) maxi = max(maxi, nums[i]);
        if(k<n)  maxi = max(maxi,nums[k]);
        
        return maxi;
    }
};