class Solution {
public:
    int getCommon(vector<int>& A, vector<int>& B) {
        int i = 0, j = 0;
        
        while (i<A.size() && j<B.size()) {
            if (A[i] == B[j])  return A[i];
            else if (A[i] < B[j]) i++;
            else j++;
        }
        return -1;
    }
};