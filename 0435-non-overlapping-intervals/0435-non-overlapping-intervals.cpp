bool cmp(vector<int>&a,vector<int>&b){
    return a[1] < b[1]; // sorting based on the end time
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& A) {
        
        sort(A.begin(),A.end(),cmp);
        int count = 0;
        int lastEndTime = A[0][1];

        for(int i=1;i<A.size();i++){
            if(A[i][0] < lastEndTime){
                count++;
            }
            else{
                lastEndTime = A[i][1];
            }
        }
        return count;
    }
};