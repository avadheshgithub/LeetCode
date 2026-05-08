class Solution {
public:
    int mySqrt(int x) {
        long long l = 0;
        long long r = x;
        
        while(l<=r){
            long long m = (l+r)/2;
            long long m_sqaq = m*m;

            if(m_sqaq==x) return m;
            else if(m_sqaq<x) l = m+1;
            else r = m-1;
        }
        return r;
    }
};