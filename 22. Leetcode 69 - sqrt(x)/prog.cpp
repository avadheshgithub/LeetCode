// sqrt(x)
// Leetcode problem number: 69

class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        bool flag = true;

        while(low<=high){
            long long mid = low + ((high-low)/2);
            if(mid*mid==x) {
                flag = false;
                return mid;
            }
            else if(mid*mid>x) high = mid-1;
            else low = mid+1;
        }
        return high;
    }
};