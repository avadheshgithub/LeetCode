// Valid Anagram
// Leetcode problem number: 242

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // Approach 1 - Sorting
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t) return true;
        else return false;
    }
};