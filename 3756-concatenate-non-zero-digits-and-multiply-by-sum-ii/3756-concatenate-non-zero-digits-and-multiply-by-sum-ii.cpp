class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> prefCnt(n + 1, 0), prefSum(n + 1, 0);
        vector<long long> prefNum(n + 1, 0), pow10(n + 1, 1);

        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int i = 0; i < n; i++) {
            prefCnt[i + 1] = prefCnt[i];
            prefSum[i + 1] = prefSum[i];
            prefNum[i + 1] = prefNum[i];

            if (s[i] != '0') {
                int d = s[i] - '0';
                prefCnt[i + 1]++;
                prefSum[i + 1] += d;
                prefNum[i + 1] = (prefNum[i] * 10 + d) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int leftCnt = prefCnt[l];
            int rightCnt = prefCnt[r + 1];
            int len = rightCnt - leftCnt;

            if (len == 0) {
                ans.push_back(0);
                continue;
            }

            long long x = (prefNum[r + 1]
                          - prefNum[l] * pow10[len] % MOD
                          + MOD) % MOD;

            long long sum = prefSum[r + 1] - prefSum[l];

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};