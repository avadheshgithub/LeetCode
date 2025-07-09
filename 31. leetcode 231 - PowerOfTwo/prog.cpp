// PowerOf2 
// LeetCode Problem 231: Power of Two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        if(n==1) return true; // till 1 
        if(n%2 != 0) return false; // not divided by 2
        return isPowerOfTwo(n/2);
    }
};