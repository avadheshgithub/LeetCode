// Reduce a number to zero
// Leetcode problem 1342

class Solution {
public:
    int numberOfSteps(int num) {
        if(num==0) return 0;
        if(num%2==0) return 1+numberOfSteps(num/2); // divided by 2
        else return 1+numberOfSteps(num-1); // if not devided
    }
};

// MEthode 02 - Iterative solution
class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        while(num > 0) {
            if(num % 2 == 0) {
                num /= 2; // divided by 2
            } else {
                num -= 1; // if not devided
            }
            steps++;
        }
        return steps;
    }
};