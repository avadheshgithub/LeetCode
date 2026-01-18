class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        
        int max_defense = 0, count = 0;
        for (auto& p : arr) {
            if (p[1] < max_defense) count++;
            else max_defense = p[1];
        }
        return count;
    }
};