class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<int>st;
        int L=0,R=0,ans=0;

        while(R<n){
            char c = s[R];
            while(st.count(c)){
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