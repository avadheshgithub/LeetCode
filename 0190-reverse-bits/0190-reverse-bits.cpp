class Solution {
public:
    int reverseBits(int n) {
        int rev = 0;
        for(int i=0;i<32;i++){
            rev = rev<<1;
            rev = rev | (n&1);
            n = n>>1;
        }
        return rev;
    }
};

/*  ( OR AND ) 

     rotate 1 bit left <<
     to know what was origional bit --> n&1
     
*/

