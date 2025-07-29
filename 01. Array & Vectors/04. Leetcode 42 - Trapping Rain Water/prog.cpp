class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        // Step 01 - store max height to left
        vector<int>prev(n);
        prev[0] = height[0];
        for(int i=1;i<n;i++){
            prev[i] = max(prev[i-1],height[i]);
        }

        // Step 02 - Store maximum height to right
        vector<int>next(n);
        next[n-1] = height[n-1];
        for(int i= n-2;i>=0;i--){
            next[i] = max(next[i+1],height[i]);
        }

        // Step 03 - calculate Water Level as Min of left & right max
        vector<int>res(n);
        for(int i=0;i<n;i++){
            res[i] = min(prev[i],next[i]);
        }

        // Step 04 - total trapped water
        int trappedWater = 0;
        for(int i=0;i<n;i++){
            trappedWater += res[i]-height[i];
        }

        return trappedWater;
    }
};