class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        for(int i=0; i<n; i++) {
            int Nidx = (i + nums[i]) % n;

            if(Nidx < 0) Nidx += n;
            res[i] = nums[Nidx];
        }
        return res;
    }
};