class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("00") == -1;
    }
};