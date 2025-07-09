// Power of three
// LeetCode Problem 326: Power of Three

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        if(n==1) return true; // till 1 --> base case
        if(n%3 != 0) return false; // not divided by 3
        return isPowerOfThree(n/3);
    }
};

// Methode 2 - bitwise operation
class Solution {
public: 
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        while(n % 3 == 0) {
            n /= 3;
        }
        return n == 1; // if n is reduced to 1, it is a power of 3
    }   
};

// Methode 3 - logarithmic approach
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        double logValue = log(n) / log(3);
        return floor(logValue) == logValue; // check if logValue is an integer

    }
};