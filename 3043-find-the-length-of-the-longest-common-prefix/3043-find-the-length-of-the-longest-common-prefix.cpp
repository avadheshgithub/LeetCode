class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> pre;
        
        for (int x : arr1) {
            string s = to_string(x);
            string Pf = "";
            for (char c : s) {
                Pf += c;
                pre.insert(Pf);
            }
        }

        int ans = 0;
        
        for (int y : arr2) {
            string s = to_string(y);
            string Pf = "";
            for (char c : s) {
                Pf += c;
                if (pre.count(Pf)) ans = max(ans, (int)Pf.size());
            }
        }
        return ans;
    }
};