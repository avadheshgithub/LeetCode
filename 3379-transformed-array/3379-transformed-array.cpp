class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        for(int i=0; i<n; i++) {
            int newIdx = (i + nums[i]) % n;

            if(newIdx < 0) newIdx += n;

            res[i] = nums[newIdx];
        }
        return res;
    }
};