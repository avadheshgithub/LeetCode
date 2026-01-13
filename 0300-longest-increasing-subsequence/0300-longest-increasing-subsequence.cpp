class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>LCS(nums.size(),1);

        int maxi = 1;

        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    LCS[i] = max(LCS[i],1+LCS[j]);
                    maxi = max(LCS[i],maxi);
                }
            }
        }
        return maxi;
    }
};