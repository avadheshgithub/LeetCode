class Solution {
public:
    int minPartitions(string s) {
        int ans = 0;
        for (char& c : s){
            ans = max(ans, c - '0');
        }
        return ans;
    }
};