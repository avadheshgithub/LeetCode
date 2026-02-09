class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        priority_queue< tuple<int,int,int>,vector<tuple<int,int,int>>,greater<> > pq;

        int maxVal = INT_MIN;

        // Step 1. push 1st ele of each list
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            maxVal = max(maxVal, nums[i][0]);
        }

        int rangeStart = 0, rangeEnd = INT_MAX;

        while (true) {
            auto [minVal, row, col] = pq.top();
            pq.pop();

            // Step 2: update best range
            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }

            // Step 3: move forward in the same list
            if (col + 1 == nums[row].size())
                break;

            int nextVal = nums[row][col + 1];
            pq.push({nextVal, row, col + 1});
            maxVal = max(maxVal, nextVal);
        }

        return {rangeStart, rangeEnd};
    }
};
