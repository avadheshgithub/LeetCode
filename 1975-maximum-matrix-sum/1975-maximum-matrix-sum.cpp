class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long total = 0;
        int neg = 0;
        int minAbs = INT_MAX;

        for(auto &R : matrix) {
            for(int val : R) {
                if (val < 0) neg++;
                total += abs(val);
                minAbs = min(minAbs, abs(val));
            }
        }

        if(neg%2==0) return total;
        return total - 2LL * minAbs;
    }
};