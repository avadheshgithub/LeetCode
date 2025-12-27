class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int>Invalid;
        stack<int>st; //idx

        for(int i=0;i<s.length();i++){  
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                if(st.empty()) Invalid.insert(i);
                else st.pop();
            }
        }

        while(!st.empty()){ 
            Invalid.insert(st.top());
            st.pop();
        }

        string res = ""; 
        for(int i=0;i<s.length();i++){
            if(Invalid.find(i)==Invalid.end()) res += s[i];
        }
        return res;
    }
};