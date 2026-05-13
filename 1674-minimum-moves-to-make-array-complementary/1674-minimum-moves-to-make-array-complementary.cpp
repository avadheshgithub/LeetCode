class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> vec(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n-1-i];

            int low = min(a, b);
            int high = max(a, b);

            vec[2] += 2;
            vec[low + 1] -= 1;
            vec[a + b] -= 1;
            vec[a + b + 1] += 1;
            vec[high + limit + 1] += 1;
        }

        int ans = INT_MAX;
        int moves = 0;

        for (int i=2; i <= 2 * limit; i++) {
            moves += vec[i];
            ans = min(ans, moves);
        }

        return ans;
    }
};