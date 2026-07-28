class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        
        for (char c:s)  freq[c-'a']++;
        
        
        string half = "";
        char mid = 0; 
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                mid = i + 'a';
            }
            half.append(freq[i] / 2, i + 'a');
        }
        

        string result = half;
        if (mid != 0) {
            result += mid;
        }
        
        reverse(half.begin(), half.end());
        result += half;
        
        return result;
    }
};