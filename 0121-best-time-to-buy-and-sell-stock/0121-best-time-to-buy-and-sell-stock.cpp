class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = INT_MIN;
        int Min = INT_MAX;

        for(auto x:prices){
            Min = min(Min,x);
            maxPro = max(maxPro,x-Min);
        }
        return maxPro;
    }
};