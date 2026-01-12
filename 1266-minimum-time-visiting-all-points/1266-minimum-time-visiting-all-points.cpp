class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& P) {
        int total_cost = 0;

        for(int i=1;i<P.size();i++){
            total_cost += max(abs(P[i][0]-P[i-1][0]),abs(P[i][1]-P[i-1][1]));
        }
        return total_cost;
    }
};