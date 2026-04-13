class Solution {
public:
    int getMinDistance(vector<int>& nums, int tar, int st) {
        int ans = INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==tar){
                ans = min(ans,abs(i-st));
            }
        }
        return ans;
    }
};