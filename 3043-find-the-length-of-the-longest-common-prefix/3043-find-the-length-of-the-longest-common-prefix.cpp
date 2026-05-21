class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> pre;
        
        for (int x : arr1) {
            string s = to_string(x);
            string pref = "";
            for (char c : s) {
                pref += c;
                pre.insert(pref);
            }
        }

        int ans = 0;
        
        for (int y : arr2) {
            string s = to_string(y);
            string pref = "";
            for (char c : s) {
                pref += c;
                if (pre.count(pref)) ans = max(ans, (int)pref.size());
            }
        }
        return ans;
    }
};