class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> strSet(nums.begin(), nums.end());
        string cur(nums.size(), '0');
        return backtrack(0, cur, strSet, nums.size());
    }

private:
    string backtrack(int i, string& cur, unordered_set<string>& strSet, int n) {
        if (i == n) 
            return strSet.count(cur) ? "" : cur;

        string res = backtrack(i + 1, cur, strSet, n);
        if (!res.empty()) return res;

        cur[i] = '1';
        return backtrack(i + 1, cur, strSet, n);
    }
};