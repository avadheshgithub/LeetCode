class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(auto x:nums){
            if(x>maxi) maxi = max(maxi,x);
            if(x<mini) mini = min(mini,x);
        }
        
        return gcd(mini,maxi);
    }
};