class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        // int --> vector<int>
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        int maxEle = INT_MIN;
        for(int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            maxEle = max(maxEle, nums[i][0]);
        }
        
        vector<int> resultRange = {-1000000, 1000000};
        
        while(!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            
            int minEle = curr[0];
            int listIdx = curr[1];
            int idx = curr[2];
            
            if(maxEle - minEle < resultRange[1] - resultRange[0]) {
                resultRange[0] = minEle;
                resultRange[1] = maxEle;
            }
            
            if(idx + 1 < nums[listIdx].size()) {
                int nextElement = nums[listIdx][idx + 1];
                pq.push({nextElement, listIdx, idx + 1});
                maxEle = max(maxEle, nextElement);
            }
            else {
                break;
            }
        }
        return resultRange;
    }
};