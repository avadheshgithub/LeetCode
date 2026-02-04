class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int L=0;
        int R=nums.size()-1;

        while(L<R){
            int mid = L+(R-L)/2;
            if(mid%2==1) mid--; // ensure mid even

            if(nums[mid]==nums[mid+1])
                L = mid+2;  //match-> go right
            else
                R = mid;  // misMatch -> Go left
        }
        return nums[L];
    }
};