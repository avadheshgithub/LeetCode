#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int global_base_ones = 0;
        for (char c : s) {
            if (c == '1') global_base_ones++;
        }

        vector<int> L_starts, R_ends;
        int i = 0;
        
        // Group all contiguous 0-blocks
        while (i < n) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') j++;
                L_starts.push_back(i);
                R_ends.push_back(j - 1);
                i = j;
            } else {
                i++;
            }
        }

        int K = L_starts.size();
        vector<int> Z(K);
        for (int k = 0; k < K; k++) {
            Z[k] = R_ends[k] - L_starts[k] + 1;
        }

        // L records lengths of inner 1-blocks strictly separating 0-blocks
        vector<int> L(K, 0); 
        for (int k = 1; k < K; k++) {
            L[k] = L_starts[k] - R_ends[k - 1] - 1;
        }

        // S records the sum of two adjacent 0-blocks
        vector<int> S(K, 0); 
        for (int k = 1; k < K; k++) {
            S[k] = Z[k - 1] + Z[k];
        }

        // Initialize Sparse Tables for O(1) Range Queries
        int LOG = 0;
        if (K > 0) {
            int temp = K;
            while (temp) { temp >>= 1; LOG++; }
            LOG += 1;
        }
        
        vector<vector<int>> Z_max_ST(LOG, vector<int>(K, 0));
        vector<vector<int>> L_min_ST(LOG, vector<int>(K, 0));
        vector<vector<int>> S_max_ST(LOG, vector<int>(K, 0));

        if (K > 0) {
            for (int k = 0; k < K; k++) Z_max_ST[0][k] = Z[k];
            for (int j = 1; j < LOG; j++) {
                for (int k = 0; k + (1 << j) <= K; k++) {
                    Z_max_ST[j][k] = max(Z_max_ST[j - 1][k], Z_max_ST[j - 1][k + (1 << (j - 1))]);
                }
            }
        }

        if (K > 1) {
            for (int k = 1; k < K; k++) L_min_ST[0][k] = L[k];
            for (int j = 1; j < LOG; j++) {
                for (int k = 1; k + (1 << j) <= K; k++) {
                    L_min_ST[j][k] = min(L_min_ST[j - 1][k], L_min_ST[j - 1][k + (1 << (j - 1))]);
                }
            }

            for (int k = 1; k < K; k++) S_max_ST[0][k] = S[k];
            for (int j = 1; j < LOG; j++) {
                for (int k = 1; k + (1 << j) <= K; k++) {
                    S_max_ST[j][k] = max(S_max_ST[j - 1][k], S_max_ST[j - 1][k + (1 << (j - 1))]);
                }
            }
        }

        int max_len = max(2, K + 1);
        vector<int> log2_table(max_len + 1, 0);
        for (int idx = 2; idx <= max_len; idx++) {
            log2_table[idx] = log2_table[idx / 2] + 1;
        }

        auto query_Z_max = [&](int l_idx, int r_idx) {
            if (l_idx > r_idx) return 0;
            int j = log2_table[r_idx - l_idx + 1];
            return max(Z_max_ST[j][l_idx], Z_max_ST[j][r_idx - (1 << j) + 1]);
        };

        auto query_L_min = [&](int l_idx, int r_idx) {
            if (l_idx > r_idx) return (int)1e9;
            int j = log2_table[r_idx - l_idx + 1];
            return min(L_min_ST[j][l_idx], L_min_ST[j][r_idx - (1 << j) + 1]);
        };

        auto query_S_max = [&](int l_idx, int r_idx) {
            if (l_idx > r_idx) return 0;
            int j = log2_table[r_idx - l_idx + 1];
            return max(S_max_ST[j][l_idx], S_max_ST[j][r_idx - (1 << j) + 1]);
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            
            // O(log K) search for bounded 0-blocks inside [l, r]
            int u = lower_bound(R_ends.begin(), R_ends.end(), l) - R_ends.begin();
            if (u == K || L_starts[u] > r) {
                ans.push_back(global_base_ones);
                continue;
            }
            
            int v = upper_bound(L_starts.begin(), L_starts.end(), r) - L_starts.begin() - 1;
            if (u >= v) {   // Less than two 0-blocks means no valid trades are possible
                ans.push_back(global_base_ones);
                continue;
            }
            
            // Truncate the outer limits conditionally 
            int Z_prime_u = min(R_ends[u], r) - max(L_starts[u], l) + 1;
            int Z_prime_v = min(R_ends[v], r) - max(L_starts[v], l) + 1;
            
            int M = max({Z_prime_u, Z_prime_v, query_Z_max(u + 1, v - 1)});
            int L_min = query_L_min(u + 1, v);
            
            int S_max = 0;
            if (v == u + 1) {
                S_max = Z_prime_u + Z_prime_v;
            } else {
                S_max = max({
                    Z_prime_u + Z[u + 1],
                    Z[v - 1] + Z_prime_v,
                    query_S_max(u + 2, v - 1)
                });
            }
            
            int gain = max(S_max, M - L_min);
            ans.push_back(global_base_ones + gain);
        }

        return ans;
    }
};