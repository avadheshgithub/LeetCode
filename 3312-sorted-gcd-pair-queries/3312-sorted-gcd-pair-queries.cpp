class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = 0;
        for (int num : nums) {
            if (num > max_val) {
                max_val = num;
            }
        }
        
        vector<long long> count(max_val + 1, 0);
        for (int num : nums) {
            count[num]++;
        }
        
        vector<long long> exact(max_val + 1, 0);
        
        for (int g = max_val; g >= 1; --g) {
            long long c = 0;
            for (int m = g; m <= max_val; m += g) {
                c += count[m];
            }
            
            long long pairs = c * (c - 1) / 2;
            
            for (int m = 2 * g; m <= max_val; m += g) {
                pairs -= exact[m];
            }
            
            exact[g] = pairs;
        }
        
        vector<long long> pref(max_val + 1, 0);
        for (int g = 1; g <= max_val; ++g) {
            pref[g] = pref[g - 1] + exact[g];
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            auto it = upper_bound(pref.begin(), pref.end(), q);
            ans.push_back(distance(pref.begin(), it));
        }
        
        return ans;
    }
};