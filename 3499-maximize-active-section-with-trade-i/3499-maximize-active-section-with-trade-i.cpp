class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
       int base_ones = 0;
        for (char c : s) {
            if (c == '1') base_ones++;
        }
        
        string t = "1" + s + "1";
        vector<int> ones;
        vector<int> zeros;
        
        int n = t.length();
        int i = 0;
        
        while (i < n) {
            int j = i;
            while (j < n && t[j] == '1') j++;
            ones.push_back(j - i);
            i = j;
            if (i >= n) break;
            
            j = i;
            while (j < n && t[j] == '0') j++;
            zeros.push_back(j - i);
            i = j;
        }
        
        int k = zeros.size();
        
        if (k < 2) {
            return base_ones;
        }
        
        vector<pair<int, int>> sorted_zeros;
        for (int idx = 0; idx < k; idx++) {
            sorted_zeros.push_back({zeros[idx], idx});
        }
        
        sort(sorted_zeros.rbegin(), sorted_zeros.rend());
        
        int max_gain = 0;
        
        for (int idx = 1; idx < k; idx++) {
            int L = ones[idx];
            
            int merged_gain = zeros[idx - 1] + zeros[idx];
            
            int other_max_zero = 0;
            
            for (int rank = 0; rank < min(3, (int)sorted_zeros.size()); rank++) {
                if (sorted_zeros[rank].second != idx - 1 && sorted_zeros[rank].second != idx) {
                    other_max_zero = sorted_zeros[rank].first;
                    break;
                }
            }
            
            int other_gain = other_max_zero - L;
            
            int current_gain = max(merged_gain, other_gain);
            max_gain = max(max_gain, current_gain);
        }
        
        return base_ones + max_gain; 
    }
};