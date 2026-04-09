class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int tar) {
        vector<int>ans(2,-1);

        // Find the first position
        int L=0, R=nums.size()-1;
        while(L<=R) {
            int mid = L+(R-L)/2;
            if(nums[mid]<tar) L=mid+1;
            else R = mid-1;
            if(nums[mid]==tar) ans[0] = mid;
        }

        // Find the last position
        L=0, R =nums.size()-1;
        while(L<=R) {
            int mid = L+(R-L)/2;
            if(nums[mid]<=tar) L=mid+1;
            else R = mid-1;
            if (nums[mid] == tar) ans[1] = mid;
        }
        return ans;
    }
};