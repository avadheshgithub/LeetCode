// Climbing Stairs 
// Leetcode problem number: 70

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int a=1,b=2;
        for(int i=3;i<=n;i++){
            int c = a+b;
            a=b;
            b=c;
        }
        return b;
    }
};

// Methode 02 - recusive with memoization
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