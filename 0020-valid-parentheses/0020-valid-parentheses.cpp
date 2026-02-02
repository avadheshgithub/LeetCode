class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>mp = {
            {')','('},
            {'}','{'},
            {']','['}
        };

        stack<char>st;

        for(auto ch:s){
            if(mp.find(ch)!=mp.end()){
                if(st.empty() or st.top()!=mp[ch]) return false;
                st.pop();
            }
            else
                st.push(ch);
        }
        return st.empty();
    }
};
