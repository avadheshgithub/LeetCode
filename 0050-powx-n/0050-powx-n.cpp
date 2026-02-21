class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double result = 1.0;
        double current = x;
        
        for (long long i = N; i > 0; i /= 2) {
            if (i % 2 == 1) {
                result *= current;
            }
            current *= current;
        }
        
        return result;
    }
};