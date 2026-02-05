class Solution {
public:
    int missingNumber(vector<int>& Arr) {
        int ans = 0;
        for(int i=0;i<Arr.size();i++){
            ans ^= (i+1 ^ Arr[i]);
        }
        return ans;
    }
};