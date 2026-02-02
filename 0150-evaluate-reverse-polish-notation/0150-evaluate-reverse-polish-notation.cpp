class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(auto ch:tokens){
            if(ch=="+" or ch=="-" or ch=="*" or ch=="/"){
                int x = st.top();  st.pop();
                int y = st.top();  st.pop();

                if(ch=="+") st.push(y+x);
                if(ch=="-") st.push(y-x);
                if(ch=="*") st.push(y*x);
                if(ch=="/") st.push(y/x);
            }
            else st.push(stoi(ch));
        }
        return st.top();
    }
};
