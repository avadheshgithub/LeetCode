// Sum of Square Numbers
// LeetCode Problem 633: Sum of Square Numbers



// Methode 01 - Two Pointers
// Time Complexity: O(sqrt(n))
// Space Complexity: O(1)   


class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0, right = sqrt(c);
        while (left <= right) {
            long long sum = left * left + right * right;
            if (sum == c) return true;
            else if (sum < c) {
                left++;
            }   
            else {
                right--;
            }   
        }
        return false;
    }
};


// Methode 02 - Brute Force TLE 
class Solution {
public:
    /*
        Let c = 41 
            x=1  y=40
            x=2  y=29
    */
    bool isPerfectSquare(int n){
        int root = sqrt(n);
        if(root*root==n) return true;
        else return false;
    }

    bool judgeSquareSum(int c) {
        int x=0;
        int y=c;
        while(x<=y){
            if(isPerfectSquare(x) && isPerfectSquare(y)) return true;
            else {
                x++;
                y--;
            }
        }
        return false;
    }
};

// methode 02 - Brute Force (optimize)
class Solution {
public:
    
    bool isPerfectSquare(int n){
        int root = sqrt(n);
        if(root*root==n) return true;
        else return false;
    }

    bool judgeSquareSum(int c) {
        int x=0;
        int y=c;
        while(x<=y){
            if(isPerfectSquare(x) && isPerfectSquare(y)) return true;
            else if(!isPerfectSquare(y)) {
                y = (int)sqrt(y) * (int)sqrt(y);
                x = c-y;
            }
            else{
                x = ((int)sqrt(x)+1) * ((int)sqrt(x)+1);
                y = c-x;
            }
        }
        return false;
    }
};


// Methode 02 - Binary Search
// Time Complexity: O(sqrt(n) * log(n))
// Space Complexity: O(1)

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long i = 0; i * i <= c; ++i) {
            long long j = c - i * i;
            long long left = 0, right = sqrt(j);    
            while (left <= right) {
                long long mid = left + (right - left) / 2;
                long long square = mid * mid;
                if (square == j) {
                    return true;
                }   
                else if (square < j) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }   
            }
        };
        return false;
    }
};
