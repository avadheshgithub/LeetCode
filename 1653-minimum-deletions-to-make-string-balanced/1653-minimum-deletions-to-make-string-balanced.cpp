class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> A(n, 0);
        vector<int> B(n, 0);

        int b_count = 0;
        for (int i = 0; i < n; i++) {
            B[i] = b_count;
            if (s[i] == 'b') b_count++;
        }

        int a_count = 0;
        for (int i = n - 1; i >= 0; i--) {
            A[i] = a_count;
            if (s[i] == 'a') a_count++;
        }

        int ans = n;
        for (int i = 0; i < n; i++) {
            ans = min(ans, A[i] + B[i]);
        }
        return ans;
    }
};