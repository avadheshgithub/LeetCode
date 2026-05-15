class Solution {
public:
    int findMin(vector<int>& nums) {
        int L=0, R=nums.size()-1;
        int ans = INT_MAX;

        while(L<=R){
            if(nums[L]<nums[R]) ans=min(ans,nums[L]);

            int mid = L+(R-L)/2;
            ans = min(ans,nums[mid]);
            
            if(nums[L] <= nums[mid])
                L = mid+1;
            else 
                R = mid-1;
        }
        return ans;
    }
};