class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& tar) {
        vector<int>maxVal(3);
        
        for(auto t:triplets){
            if(t[0]<=tar[0] && t[1]<=tar[1] && t[2]<=tar[2]){
                maxVal[0] = max(maxVal[0],t[0]);
                maxVal[1] = max(maxVal[1],t[1]);
                maxVal[2] = max(maxVal[2],t[2]);
            }
        }
        return maxVal==tar
    }
};