class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int min = *min_element(nums.begin(),nums.end());
        int max = *max_element(nums.begin(),nums.end());
        
        int sum = max-min;

        return (long long) k*sum;


    }
};