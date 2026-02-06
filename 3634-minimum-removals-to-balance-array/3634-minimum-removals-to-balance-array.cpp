class Solution {
public:
    int minRemoval(vector<int>& nums, int k ) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = n, R = 0;
        for (int L=0;L<n; ++L) {
            while (R<n && nums[R] <= static_cast<long long>(nums[L]) * k) {
                ++R;
            }
            ans = min(ans, n-(R-L));
        }
        return ans;
    }
};