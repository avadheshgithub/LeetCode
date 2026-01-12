class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];

        int res = maxi;

        for(int i=1;i<nums.size();i++){
            int temp = max(nums[i],max(nums[i]*maxi,nums[i]*mini));
            mini = min(nums[i],min(nums[i]*maxi,nums[i]*mini));

            maxi = temp;
            res = max(res,maxi);
        }
        return res;
    }
};