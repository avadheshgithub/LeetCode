// Max Count of Positive and Negative Integers
// Leetcode 2529

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int Ncount = 0;
        int Pcount = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) Pcount++;
            if(nums[i]<0) Ncount++;
        }
        return max(Pcount,Ncount);
    }
};