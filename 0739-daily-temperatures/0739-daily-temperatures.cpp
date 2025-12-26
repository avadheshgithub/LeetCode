class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]>nums[st.top()]){
                int idx = st.top();
                st.pop();
                ans[idx] = i-idx;
            }
            st.push(i);
        }
        return ans;
    }
};