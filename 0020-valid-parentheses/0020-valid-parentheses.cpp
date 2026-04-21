class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>mp = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> st;

        for (char c : s) {
            if (mp.find(c)!= mp.end()){ // closing
                if (st.empty() || st.top() != mp[c]) {
                    return false; 
                }
                st.pop();
            }
            else{
                st.push(c);//opening
            }
        }
        return st.empty();
    }
};