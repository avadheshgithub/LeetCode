class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;

        int msk=1;
        while(msk<n)
            msk = (msk << 1) | 1; 
        
        return n ^ msk;
    }
};