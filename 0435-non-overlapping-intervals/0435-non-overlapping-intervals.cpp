class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& Arr) {
       sort(Arr.begin(),Arr.end());

       int prev = 0;
       int count = 0;

       for(int i=1;i<Arr.size();i++){
            if(Arr[prev][1]>Arr[i][0]){
                if(Arr[prev][1]>Arr[i][1]){
                    prev = i;
                }
                count++;
            }
            else{
                prev = i;
            }
        } 
       return count;
    }
};