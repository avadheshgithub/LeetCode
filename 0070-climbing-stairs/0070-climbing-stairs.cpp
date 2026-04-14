class Solution {
public:
    int climb(int n,vector<int>&helper){
        if(n<=2) return n;
        if(helper[n] != -1) return helper[n];
        helper[n] = climb(n-1,helper) + climb(n-2,helper);
        return helper[n];
    }

    int climbStairs(int n) {
        vector<int>helper(n+1,-1);
        return climb(n,helper);
    }
};