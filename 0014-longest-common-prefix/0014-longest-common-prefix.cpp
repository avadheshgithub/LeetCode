class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string Prefix = strs[0];
        
        for (int i=1;i<strs.size();i++) {
            while(strs[i].find(Prefix)!=0) {
                Prefix = Prefix.substr(0,Prefix.length() - 1); // reduce by 1
                
                if (Prefix.empty()){
                    return "";
                }
            }
        }
        return Prefix;
    }
};