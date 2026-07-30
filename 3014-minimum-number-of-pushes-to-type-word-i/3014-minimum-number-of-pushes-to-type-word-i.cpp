class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int Push = 0;
        
        int mul = 1; 
        while (n > 0) {
            int char_p = std::min(8, n);
            Push += char_p * mul;
            
            n -= 8;
            mul++;
        }
        return Push;
    }
};