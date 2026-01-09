class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;

        int temp2 = 1;
        int temp1 = 1;

        for(int i =2; i<=n; i++) {
            int curr = temp1+temp2;
            temp2 = temp1;
            temp1 = curr;
        }
        return temp1;
    }
};