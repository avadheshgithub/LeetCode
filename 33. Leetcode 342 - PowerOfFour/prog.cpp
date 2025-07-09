// Power of Four
// LeetCode Problem 342: Power of Four

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0) return false;
        if(n==1) return true; // till 1 --> base case
        if(n%4 != 0) return false; // n is not devided by 4
        return isPowerOfFour(n/4);
    }
};

// methode 2 - betwise operation

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;    
        if(n & (n - 1)) return false; // check if n is a power of 2
        return (n - 1) % 3 == 0; // check if n is a power of 4
    }
};

// methode 3 - logaritmic approach
class Solution {    
public:

    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        double logValue = log(n) / log(4);
        return floor(logValue) == logValue; // check if logValue is an integer
    }   
};

// methode 4 - bit manipulation
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        if((n & (n - 1)) != 0) return false; // check if n is a power of 2
        return (n & 0x55555555) != 0; // check if the only set bit is at an even position
    }
};