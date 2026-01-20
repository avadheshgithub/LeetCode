class Solution {
public:
    vector<int> finalPrices(vector<int>& a) {
        stack<int>st;
        for(int i=0;i<a.size();i++){
            while(!st.empty() && a[i]<=a[st.top()]){
                a[st.top()] -= a[i]; // Final Price = price - Discubt
                st.pop();
            }
            st.push(i);
        }
        return a;
    }
};