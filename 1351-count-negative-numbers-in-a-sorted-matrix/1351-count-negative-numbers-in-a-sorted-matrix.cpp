class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;

        for(auto& row : grid){
            int idx = upper_bound(begin(row), end(row), 0, greater<int>()) - begin(row);
            count += row.size()-idx;
        }
        return count;
    }
};