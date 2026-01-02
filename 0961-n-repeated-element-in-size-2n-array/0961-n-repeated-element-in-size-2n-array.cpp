class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // n time repeated --> ele present max gap of i-1 or i-2 --> ans

        for(int i=2;i<nums.size();i++){
            if(nums[i]==nums[i-1] || nums[i]==nums[i-2]) return nums[i];
        }
        return nums.back();
    }
};