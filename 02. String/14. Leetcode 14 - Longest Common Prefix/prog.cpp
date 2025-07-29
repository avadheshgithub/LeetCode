// Longest Common Prefix
// LeetCode Problem 14: Longest Common Prefix


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Aproach - two Pointer and sorting

        int n = strs.size();
        sort(strs.begin(),strs.end());  // [flight,flow,flower]

        string first = strs[0];
        string last = strs[n-1];

        string ans = "";
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i] == last[i]) ans += first[i];
            else return ans;
        }

        return ans;
    }
};