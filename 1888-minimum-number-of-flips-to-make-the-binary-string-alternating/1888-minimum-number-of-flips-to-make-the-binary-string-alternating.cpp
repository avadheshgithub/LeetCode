class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int flip = INT_MAX;
        int diff1 = 0; 
        int diff2 = 0; 

        for (int i=0; i<2*n; i++) {
            char exp1 = (i % 2 == 0) ? '0' : '1';
            char exp2 = (i % 2 == 0) ? '1' : '0';

            if (s[i % n] != exp1) diff1++;
            if (s[i % n] != exp2) diff2++;

            if (i >= n) {
                int idx = i - n;
                char idx1 = (idx % 2 == 0) ? '0' : '1';
                char idx2 = (idx % 2 == 0) ? '1' : '0';
                
                if (s[idx % n] != idx1) diff1--;
                if (s[idx % n] != idx2) diff2--;
            }

            if (i >= n-1) {
                flip = min({flip, diff1, diff2});
            }
        }
        return flip;
    }
};