class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = nums[0];

        for(auto x:nums){
            if(currSum<0) currSum = 0;
            currSum = currSum + x;
            maxSum = max(maxSum,currSum);
        }
        return maxSum;
    }
};