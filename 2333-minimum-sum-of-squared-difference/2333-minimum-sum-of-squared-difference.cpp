
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = 1LL * k1 + k2;
        int n = nums1.size();

        vector<long long> diff(n);
        long long total = 0, mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx, diff[i]);
        }

        if (total <= k) return 0;

        // Binary search for the minimum possible maximum difference
        long long low = 0, high = mx;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long operations = 0;

            for (long long d : diff) {
                if (d > mid)
                    operations += d - mid;
            }

            if (operations <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long threshold = low;
        long long used = 0;

        // Reduce all differences to the threshold
        for (long long &d : diff) {
            if (d > threshold) {
                used += d - threshold;
                d = threshold;
            }
        }

        // Distribute remaining operations
        long long remaining = k - used;

        for (long long &d : diff) {
            if (remaining > 0 && d == threshold) {
                d--;
                remaining--;
            }
        }

        long long ans = 0;

        for (long long d : diff) {
            ans += d * d;
        }

        return ans;
    }
};
