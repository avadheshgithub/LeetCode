class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
                
        sort(arr.begin(),arr.end());
        vector<vector<int>> result;

        int i = 0;
        while (i < arr.size() - 1) {
            if (arr[i][1] >= arr[i+1][0]) {
                arr[i+1][0] = arr[i][0];
                arr[i+1][1] = max(arr[i][1], arr[i+1][1]);
            } else {
                result.push_back(arr[i]);
            }
            i++;
        }
        result.push_back(arr[i]);
        
        return result;
    }
};