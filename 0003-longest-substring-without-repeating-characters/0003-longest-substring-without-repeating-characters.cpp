class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0 or s.size()==1) return s.size();

        unordered_set<char>st;
        int L=0, R=0, ans=0;
 
        while(R<s.length()){
            char c = s[R];
            while(st.find(c)!=st.end()){
                st.erase(s[L]);
                L++;
            }
            st.insert(c);
            ans = max(ans,R-L+1);
            R++;
        }
        return ans;
    }
};