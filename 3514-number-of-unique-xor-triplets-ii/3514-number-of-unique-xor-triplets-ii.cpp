class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        bool pairs[2048] = {false};
        bool triplets[2048] = {false};
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i <= k; i++) {
                pairs[nums[i] ^ nums[k]] = true;
            }
         
            for (int v = 0; v < 2048; v++) {
                if (pairs[v]) {
                    triplets[v ^ nums[k]] = true;
                }
            }
        }
        
        int uniqueCount = 0;
        for (int v = 0; v < 2048; v++) {
            if (triplets[v]) {
                uniqueCount++;
            }
        }
        
        return uniqueCount;
    }
};