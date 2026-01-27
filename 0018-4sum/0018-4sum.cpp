typedef long long ll;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {

        // Optimized Ans - Two Pointer (O(nlogn + n^3))
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;

            for (int j = i + 1; j < n; j++) {
                if (j>i+1 && nums[j] == nums[j-1]) continue;

                int p=j+1, q =n-1;
                while (p < q) {
                    ll sum = (ll)nums[i] + (ll)nums[j] + (ll)nums[p] + (ll)nums[q];
                    if (sum < tar) p++;
                    else if (sum > tar) q--;
                    else {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;
                        while (p < q && nums[p] == nums[p - 1]) p++;
                        while (p < q && nums[q] == nums[q + 1]) q--;
                    }
                }
            }
        }
        return ans;
    }
};