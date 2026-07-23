
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
  
        if (n == 1) return 1;
        if (n == 2) return 2;
        
    
        int next_power_of_2 = 1;
        while (next_power_of_2 <= n) {
            next_power_of_2 <<= 1;
        }
        
        return next_power_of_2;
    }
};