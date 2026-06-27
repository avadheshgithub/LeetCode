class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        int ans = 1;

        if (freq.count(1)) {
            ans = max(ans, freq[1] % 2 ? freq[1] : freq[1] - 1);
        }

        for (auto &[x, cnt] : freq) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (freq.count(cur) && freq[cur] >= 2) {
                len += 2;

                if (cur > 1000000000LL) break;
                cur = cur * cur;
            }

            if (freq.count(cur))
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};