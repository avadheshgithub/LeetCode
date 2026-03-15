class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int Lsum = 0;
        int Rsum = sum;
        for (int i = 0; i < n; i++) {
            if(nums[i] == 0){
                if (Lsum - Rsum >= 0 && Lsum - Rsum <= 1)  ans++;
                if (Rsum - Lsum >= 0 && Rsum - Lsum <= 1)  ans++;
            } 
            else{
                Lsum += nums[i];
                Rsum -= nums[i];
            }
        }
        return ans;
    }
};