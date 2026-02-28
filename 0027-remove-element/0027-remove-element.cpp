class Solution {
public:
    int removeElement(vector<int>& A, int val) {
        int n = A.size();
        int i = -1;
    
        for(int j=0; j<n;j++){
            if(A[j]!=val){
                i++;
                A[i] = A[j];
            }
        }
        return i+1 ;
    }
};