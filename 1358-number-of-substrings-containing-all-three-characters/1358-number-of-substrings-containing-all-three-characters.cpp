class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastIdx(3, -1);  
        int count = 0;

        for(int i = 0; i < s.length(); i++) {
            lastIdx[s[i] - 'a'] = i;
            
            if(lastIdx[0] != -1 && lastIdx[1] != -1 && lastIdx[2] != -1) {
                count += 1 + min(lastIdx[0], min(lastIdx[1], lastIdx[2]));
            }
        }
        return count;
    }
};