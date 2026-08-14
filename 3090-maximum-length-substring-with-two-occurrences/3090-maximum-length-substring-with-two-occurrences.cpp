class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26, 0);
        int len = 0;
        int L = 0;

        for (int R = 0; R < s.length(); ++R) {
            freq[s[R]-'a']++;
            while (freq[s[R]-'a'] > 2){
                freq[s[L]-'a']--;
                L++;
            }
            len = max(len, R - L + 1);
        }
        return len;
    }
};