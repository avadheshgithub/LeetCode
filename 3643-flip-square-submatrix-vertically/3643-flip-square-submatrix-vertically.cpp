class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& arr, int x, int y, int k) {
        for (int i = x; i < x + k / 2; i++) {
        int i2 = x + k - 1 - (i - x);
        for (int j = y; j < y + k; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[i2][j];
            arr[i2][j] = temp;
        }
    }
    return arr;
    }
};