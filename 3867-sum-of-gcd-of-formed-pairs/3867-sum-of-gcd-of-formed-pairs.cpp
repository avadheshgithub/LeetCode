class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n);
        int mxi = nums[0];
        
        for (int i = 0; i < n; ++i) {
            mxi = max(mxi, nums[i]);
            vec[i] = std::gcd(nums[i], mxi);
        }
        
        sort(vec.begin(), vec.end());
        
        long long totalSum = 0;
        int L = 0;
        int R = n - 1;
        
        while (L < R) {
            totalSum += std::gcd(vec[L], vec[R]);
            L++;
            R--;
        }
        
        return totalSum;
    }
};