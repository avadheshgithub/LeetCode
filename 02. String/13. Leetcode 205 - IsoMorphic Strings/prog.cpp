// IsoMorphic Strings
// Leetcode Problem 205: Isomorphic Strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        int mapS[128] = {0};  
        int mapT[128] = {0};    

        for(int i=0;i<s.size();i++){
            if(mapS[s[i]] != mapT[t[i]]) return false;
            mapS[s[i]] = i+1;
            mapT[t[i]] = i+1;
        }

        return true;
    }
};