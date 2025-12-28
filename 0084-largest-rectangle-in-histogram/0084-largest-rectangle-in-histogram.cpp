class Solution {
public:
    int largestRectangleArea(vector<int>& Arr) {
        int maxArea = 0;
        int n= Arr.size();
        stack<int>st;

        for(int i=0;i<=n;i++){
            int currHeight = (i==n) ? 0 : Arr[i];
            while(!st.empty() && currHeight < Arr[st.top()]){
                int height = Arr[st.top()];
                st.pop();
                int width = st.empty()? i : i- st.top()-1;
                maxArea = max(maxArea,height*width);
            }
            st.push(i);
        }
        return maxArea;
    }
};