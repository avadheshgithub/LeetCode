class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while(n!=0){
            count++;
            n = n & (n-1);
        }
        return count;
    }
};

/* 
    AND ope --> 0101 
                 <-1 shift by 1 && if ans=1 count++
                   --
                   1
*/

           // OR

/*
  (n && n-1) until n==0 and count++;

*/