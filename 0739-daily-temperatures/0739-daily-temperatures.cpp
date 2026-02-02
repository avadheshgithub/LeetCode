class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
       stack<int>st;
       vector<int>ans(arr.size());

       for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[i]>arr[st.top()]){
                int idx = st.top();
                st.pop();
                ans[idx] = i-idx;
            }
            st.push(i);
        } 
        return ans;
    }
};
