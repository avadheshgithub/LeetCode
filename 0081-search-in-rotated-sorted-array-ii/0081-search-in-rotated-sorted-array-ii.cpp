class Solution {
public:
    bool search(vector<int>& nums, int tar) {
         int st=0, end=nums.size()-1;
        while(st <= end){
            int mid = st+(end-st)/2;
            if(nums[mid]==tar) return true;
            
            // Handle duplicates
            if(nums[st]==nums[mid] && nums[end]==nums[mid]) {
                st++;
                end--;
            }
            else if(nums[st]<=nums[mid]){ // st side is sorted
                if(nums[st]<=tar && tar<nums[mid]) end=mid-1;
                else st = mid+1;
            }
            else { // end side sorted
                if(nums[mid]<tar && tar<=nums[end]) st=mid+1;
                else end = mid-1;
            }
        }
        return false;
    }
};