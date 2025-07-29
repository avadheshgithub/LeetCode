// Special Array With x Elements Greater Than or Equal X
// Leetcode problem number: 1608

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();//5
        if(nums[0]>=n) return n;
        for(int i=0;i<n;i++){ // 0,0,3,4,4   i=2,len=3
            int len = n-i;
            if(nums[i]>=len && nums[i] !=nums[i-1] && len>nums[i-1]){
                return len;
            }
        }
        return -1;
    }
};